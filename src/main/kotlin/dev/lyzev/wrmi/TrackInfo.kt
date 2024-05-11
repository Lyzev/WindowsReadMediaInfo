package dev.lyzev.wrmi

import javax.imageio.ImageIO

/**
 * Data class that holds information about a track.
 *
 * @param title The title of the track.
 * @param artist The artist of the track.
 * @param thumbnailPng The thumbnail of the track.
 * @param time The time the track was played.
 * @param duration The duration of the track.
 * @param owner The source application of the track.
 */
data class TrackInfo(
    val title: String,
    val artist: String,
    val thumbnailPng: ByteArray,
    val time: Long,
    val duration: Long,
    val owner: String
) {

    val thumbnail by lazy {
        if (thumbnailPng.isEmpty()) {
            null
        } else {
            ImageIO.read(thumbnailPng.inputStream())
        }
    }

}
