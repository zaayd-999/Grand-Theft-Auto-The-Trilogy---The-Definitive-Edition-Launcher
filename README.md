# GTA Launcher – The Definitive Edition

A custom launcher for **Grand Theft Auto: The Trilogy – The Definitive Edition** built using **C++/CLI Windows Forms**.  
This launcher provides clickable game images, a background, sound effects, and configuration management.

---

## Launcher Preview

<center>
    <img src="https://i.ibb.co/MkzJV6GZ/image.png" width="300" />
</center>
---

## Features

- Launch **GTA III, Vice City, and San Andreas** directly from the launcher.  
- **Clickable images** for each game.  
- Custom **background and icon**.  
- Reads **configuration (`config.ini`)** for game paths.  
- Optional **sound effects** when interacting with the launcher.  

---

## Quick Start

- Launch `Grand Theft Auto The Trilogy - The Definitive Edition Launcher.exe`
- Make sure the **Resources** folder is in the **same directory** as the `.EXE`

---

## Project Structure

```arduino
GTA_Launcher/
├─ Resources/
│   ├─ images/
│   │   ├─ play_btn.png
│   │   ├─ background.png       
│   │   ├─ vc.jpg      
│   │   ├─ vc_d.png   
│   │   ├─ 3.jpg    
│   │   ├─ 3_d.png              
│   │   ├─ sa.jpg
│   │   └─ sa_d.png   
│   ├─ icon/
│   │   └─ app_logo.ico         
│   ├─ sound/
│   │   ├─ 3.wav
│   │   ├─ sa.wav
│   │   ├─ vc.wav
│   │   └─ default.wav
│   └─ config.ini
├─ form.cpp
└─ form.h
```

---

## Config.ini

```yaml
GTA3=PathToGTA3
GTASA=PathToGTASA
GTAVC=PathToGTAVC
```
- Update the paths to match your local installation directories.  
- The launcher reads this file at startup to know where the games are located.

---

## How to Use

1. Open the **solution in Visual Studio**.  
2. Make sure the **Resources folder** is included in the project.  
3. Set the **application icon** in project properties (so the EXE shows it).  
4. Build the solution (`Release` or `Debug`).  
5. Place `config.ini` in Resources. 
6. Run the launcher and click on the game images to launch the respective GTA game.

---

## Requirements

- **Windows** OS  
- **.NET Framework 4.7.2** (or higher)  
- **Visual Studio** (2017 or newer) with **C++/CLI support**  

---

## License

This project is for **educational purposes**. Do not redistribute the launcher with copyrighted game files.

