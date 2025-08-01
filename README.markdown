# 🤖 JARVIS - Chat Bot Assistant 🚀

Welcome to **Jarvis**, a fun and interactive C-based chatbot assistant designed to bring a touch of AI magic to your Windows desktop! 🎉 Inspired by the iconic assistant from Iron Man, Jarvis responds to voice-like text commands, helping you with tasks like setting reminders, checking the time, opening the camera, playing music, and more. With a friendly interface and customizable features, Jarvis is here to make your day easier and more enjoyable! 😎

---

## 🌟 Project Overview

Jarvis is a lightweight command-line chatbot that processes user inputs to perform various tasks. Built in C, it uses string matching to identify commands and execute actions like managing reminders, launching applications, or displaying the current time. Perfect for Windows users looking for a simple yet powerful desktop assistant! 🖥️

---

## ✨ Key Features

- **👋 Greetings**: Responds with personalized greetings like "Hello BOSS!" or "Yo BOSS!".
- **📝 Reminders**: Set and view reminders stored in a text file.
- **📸 Camera Control**: Opens the Windows Camera app with a single command.
- **🕒 Time & Date**: Displays the current date and time in a clean format.
- **🎵 Music Playback**: Plays music files using `mpg123` (configurable for your favorite tracks).
- **🔍 Command Recognition**: Supports natural language inputs with keywords like "set", "play", or "time".
- **😄 Fun & Engaging**: Randomizes greetings for a lively user experience.

---

## 🛠️ Project Structure

The project is organized into modular C files and a text file for reminders:

- `jarvis.c`: The main driver program, handling user input and coordinating actions.
- `command.h`: Header file defining enums, structures, and function prototypes.
- `command.c`: Implements command processing, including greeting detection, reminder management, time display, and music/camera triggers.
- `reminders.txt`: Stores user-set reminders in a simple text format.

---

## 🚀 Getting Started

### Prerequisites

- A C compiler (e.g., `gcc` for Windows, such as MinGW or MSYS2)
- Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `time.h`, `unistd.h`)
- Windows operating system
- `mpg123` for music playback (optional, install via MSYS2 or similar: `pacman -S mpg123`)

### Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/jarvis-assistant.git
   cd jarvis-assistant
   ```
2. Compile the project:

   ```bash
   gcc -o jarvis jarvis.c command.c
   ```
3. Ensure `reminders.txt` is in the same directory (created automatically if absent).
4. For music playback, install `mpg123` and update the music file path in `jarvis.c`.
5. Run the assistant:

   ```bash
   ./jarvis
   ```

---

## 🎮 How to Use

1. **Launch Jarvis**: Run the executable:

   ```bash
   ./jarvis
   ```

   Jarvis greets you with a random message like:

   ```
   <=_=> Hey BOSS! What can I do for you?
   ```

2. **Enter Commands**: Type a command at the `<-_->` prompt. Examples:

   - **Greeting**: `Hi Jarvis` → `<=_=> Yo BOSS! What can I do for you?`
   - **Set Reminder**: `set reminder buy milk` → `<=_=> Reminder is set for buy milk`
   - **Show Reminders**: `show reminders` → Lists all saved reminders
   - **Time/Date**: `what's the time` → `<=_=> It is: [2025-08-02] [12:37:45 AM]`
   - **Camera**: `open camera` → Opens the Windows Camera app
   - **Music**: `play music` → Plays the specified music file
   - **Unknown Command**: `do something` → `<=_=> OOPS! I don't get it BOSS...`

3. **Exit**: Press `Ctrl+C` to stop music or close the program manually.

---

## 📂 Command Processing

- **Command Types**: Defined in `command.h` as an enum (`GREETING`, `REMINDER`, `CAMERA`, `TIME`, `MUSIC`, `UNKNOWN`).
- **Keyword Matching**: Uses case-insensitive string matching (`strcasestr`) to detect keywords like:
  - Greetings: `Hello`, `Hi`, `Hey`, `Jarvis`, etc.
  - Reminders: `reminder`, `set`, `note` (write); `show`, `open`, `tell`, `saved` (read)
  - Camera: `camera`, `video`, `picture`
  - Time: `time`, `date`
  - Music: `music`, `song`, `audio`, `play`
- **Reminder Storage**: Saved in `reminders.txt` with one reminder per line.
- **System Integration**:
  - Camera: Launches `microsoft.windows.camera:` via `system()`.
  - Music: Uses `mpg123` to play MP3 files (path configurable in `jarvis.c`).

---

## 🎉 Example in Action

**Launch Jarvis**:

```bash
./jarvis
<=_=> Welcome back BOSS! What can I do for you?
```

**Set a Reminder**:

```
<-_-> set reminder call mom
<=_=> Reminder is set for call mom
```

**View Reminders**:

```
<-_-> show reminders
<=_=> Here are your saved reminders:
	Reminder 1 : buy banana
	Reminder 2 : call mom
```

**Check Time**:

```
<-_-> what's the time
<=_=> It is: [2025-08-02] [12:37:45 AM]
```

**Play Music**:

```
<-_-> play music
<=_=> Ok BOSS, Playing music....
<=_=> Use [ctrl + c] to stop music
```

**Open Camera**:

```
<-_-> open camera
<=_=> Ok BOSS, Opening Camera....
```

---

## 💡 Tips & Notes

- **Customization**: Edit `greet`, `write_command`, `read_command`, or other keyword arrays in `jarvis.c` and `command.c` to add new commands or responses.
- **Music Path**: Update the MP3 file path in `jarvis.c` to your preferred track.
- **Reminder File**: Ensure `reminders.txt` is writable in the program directory.
- **Windows Compatibility**: Tested on Windows with MinGW/MSYS2; ensure `mpg123` is installed for music functionality.
- **Extensibility**: Add new command types by extending the `Command` enum and adding logic in `command.c`.

---

## 🤝 Contributing

We’d love to make Jarvis even smarter! 🎉

1. Fork the repository.
2. Create a feature branch (`git checkout -b feature/new-command`).
3. Commit your changes (`git commit -m 'Add new command feature'`).
4. Push to the branch (`git push origin feature/new-command`).
5. Open a pull request.

Share ideas or report bugs via GitHub Issues! 🐛

---

## 📜 License

This project is licensed under the MIT License. See the `LICENSE` file for details.

---

## 🌈 Why This Project?

Jarvis brings a playful, Iron Man-inspired assistant to your Windows desktop, blending utility with personality! Whether you’re setting reminders, checking the time, or jamming to music, Jarvis makes routine tasks fun and interactive. Perfect for coders, tech enthusiasts, or anyone wanting a quirky desktop companion. Power up your desktop with Jarvis today! 🚀