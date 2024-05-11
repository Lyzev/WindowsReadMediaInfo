package dev.lyzev.wrmi

fun main() {
    WindowsReadMediaInfo.getCurrentMediaInfo().forEach {
        println(it)
    }
}
