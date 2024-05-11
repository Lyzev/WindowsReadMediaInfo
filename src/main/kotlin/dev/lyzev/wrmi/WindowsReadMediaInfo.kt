@file:Suppress("PLATFORM_CLASS_MAPPED_TO_KOTLIN")

package dev.lyzev.wrmi

import java.io.File
import java.util.List

object WindowsReadMediaInfo {

    init {
        val tmpFile = File.createTempFile("wrmi", ".dll")
        tmpFile.writeBytes(javaClass.getResourceAsStream("/WindowsReadMediaInfo.dll")!!.readAllBytes())
        System.load(tmpFile.canonicalPath)
    }

    @JvmStatic
    external fun getCurrentMediaInfo(): List<TrackInfo>

}
