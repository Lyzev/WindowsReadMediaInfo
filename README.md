<h1 align="center">WindowsReadMediaInfo</h1>

<p align="center">Kotlin Wrapper for getting Windows Media Player Metadata.</p>

<div align="center">
    <a href="https://lyzev.github.io/discord"><img src="https://img.shields.io/discord/610120595765723137?logo=discord" alt="Discord"/></a>
    <br><br>
    <img src="https://img.shields.io/github/last-commit/Lyzev/WindowsReadMediaInfo" alt="GitHub last commit"/>
    <img src="https://img.shields.io/github/commit-activity/w/Lyzev/WindowsReadMediaInfo" alt="GitHub commit activity"/>
    <br>
    <img src="https://img.shields.io/github/languages/code-size/Lyzev/WindowsReadMediaInfo" alt="GitHub code size in bytes"/>
    <img src="https://img.shields.io/github/contributors/Lyzev/WindowsReadMediaInfo" alt="GitHub contributors"/>
</div>

## Usage

[![](https://jitpack.io/v/Lyzev/WindowsReadMediaInfo.svg?label=Release)](https://jitpack.io/#Lyzev/WindowsReadMediaInfo)

### Import

Replace `${version}` with the current version!

<details>
        <summary>Gradle KTS</summary>

```kt
repositories {
    maven("https://jitpack.io")
}

dependencies {
    implementation("com.github.Lyzev:WindowsReadMediaInfo:${version}")
}
```

</details>

<details>
        <summary>Gradle Groovy</summary>

```groovy
repositories {
    maven { url 'https://jitpack.io' }
}

dependencies {
    implementation 'com.github.Lyzev:WindowsReadMediaInfo:${version}'
}
```

</details>

<details>
        <summary>Maven</summary>

```xml

<repositories>
    <repository>
        <id>jitpack.io</id>
        <url>https://jitpack.io</url>
    </repository>
</repositories>

<dependencies>
    <dependency>
        <groupId>com.github.Lyzev</groupId>
        <artifactId>WindowsReadMediaInfo</artifactId>
        <version>${version}</version>
    </dependency>
</dependencies>
```

</details>

<details>
        <summary>Raw Jar</summary>

1. Go to the [release page](https://github.com/Lyzev/WindowsReadMediaInfo/releases).
2. Download WindowsReadMediaInfo-${version}.jar.
3. Add the jar to your classpath.

</details>

### Example

```kt
fun main() {
    WindowsReadMediaInfo.getCurrentMediaInfo().forEach {
        println(it)
    }
}
```

## Bugs and Suggestions

### Discord

For assistance with minor concerns, feel free to join our supportive community on
the [Discord server](https://lyzev.github.io/discord). Our friendly members and staff are ready to help you.

### GitHub

To ensure a prompt and effective resolution of bugs or to share your suggestions, please submit them through
the [issue tracker](https://github.com/Lyzev/WindowsReadMediaInfo/issues) of this repository. Kindly utilize the provided templates
and make sure to include all relevant details that would help us understand your issue better. Your cooperation is
greatly appreciated.