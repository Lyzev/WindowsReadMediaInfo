#include <iostream>
#include <vector>
#include <fstream>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Streams.h>
#include <jni.h>

using namespace winrt;
using namespace Windows::Media::Control;
using namespace Windows::Storage::Streams;

extern "C" JNIEXPORT jobject JNICALL Java_dev_lyzev_wrmi_WindowsReadMediaInfo_getCurrentMediaInfo(JNIEnv* env, jclass clz) {
    GlobalSystemMediaTransportControlsSessionManager smtc = GlobalSystemMediaTransportControlsSessionManager::RequestAsync().get();
    auto sessions = smtc.GetSessions();
    jclass listClass = env->FindClass("Ljava/util/LinkedList;");
    jmethodID listConstructor = env->GetMethodID(listClass, "<init>", "()V");
    jmethodID listAdd = env->GetMethodID(listClass, "add", "(Ljava/lang/Object;)Z");
    jclass trackInfoClass = env->FindClass("Ldev/lyzev/wrmi/TrackInfo;");
    jmethodID trackInfoConstructor = env->GetMethodID(trackInfoClass, "<init>", "(Ljava/lang/String;Ljava/lang/String;[BJJLjava/lang/String;)V");
    jobject list = env->NewObject(listClass, listConstructor);

    for (int i = 0; i < sessions.Size(); ++i) {
        auto session = sessions.GetAt(i);
        auto mediaProps = session.TryGetMediaPropertiesAsync().get();
        auto title = to_string(mediaProps.Title());
        auto artist = to_string(mediaProps.Artist());
        auto thumbnail = mediaProps.Thumbnail().OpenReadAsync().get();
        auto start = std::chrono::duration_cast<std::chrono::milliseconds>(session.GetTimelineProperties().StartTime()).count();
        auto time = std::chrono::duration_cast<std::chrono::milliseconds>(session.GetTimelineProperties().Position()).count();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(session.GetTimelineProperties().EndTime()).count();
        auto owner = to_string(session.SourceAppUserModelId());
        auto reader = DataReader(thumbnail.GetInputStreamAt(0));
        reader.LoadAsync(thumbnail.Size()).get();
        std::vector<uint8_t> buffer(thumbnail.Size());
        auto bufferView = array_view<uint8_t>(buffer);
        reader.ReadBytes(bufferView);
        reader.Close();

        jstring jTitle = env->NewStringUTF(title.c_str());
        jstring jArtist = env->NewStringUTF(artist.c_str());
        jstring jOwner = env->NewStringUTF(owner.c_str());

        jbyteArray jThumbnail = env->NewByteArray(buffer.size());
        env->SetByteArrayRegion(jThumbnail, 0, buffer.size(), reinterpret_cast<jbyte*>(buffer.data()));

        jobject trackInfo = env->NewObject(trackInfoClass, trackInfoConstructor, jTitle, jArtist, jThumbnail, time - start, duration - start, jOwner);
        env->CallBooleanMethod(list, listAdd, trackInfo);
    }

    return list;
}
