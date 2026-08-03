# MPR_CS_26_T? — Self-Driving Rover (BCS586 Mini Project)

A rover that learns to drive itself, trained on our own manual-driving data via
behavior cloning, with OpenCV-based perception, a live web dashboard, and an
autopilot toggle for switching between manual and policy-driven control.

Full architecture, hardware BOM, and phased plan: see `/docs`.

## Repo Structure

```
firmware/     ESP32 + ESP32-CAM code (PlatformIO)
brain/        OpenCV perception, compression, and the behavior-cloned policy (Python)
backend/      Command arbiter + WebSocket server (Python)
frontend/     Live dashboard, manual controls, autopilot toggle
docs/         Project plan, architecture diagrams, data/message schema
```

**Current status:** only `firmware/` exists so far, with a minimal build
confirming the ESP32 toolchain compiles correctly. `brain/`, `backend/`, and
`frontend/` are not built yet, they're listed above so the structure is clear
going in.

## Prerequisites

- **For firmware work:** VS Code + the PlatformIO IDE extension (installs the
  ESP32 toolchain automatically on first use). No manual Arduino IDE setup needed.
- **For brain/backend/frontend work (once they exist):** Python 3.11+, and
  Docker (Docker Desktop is easiest) so everyone runs the same dependency
  versions regardless of laptop OS.
- **Git**, obviously, and ideally add yourself to the repo as a collaborator
  before cloning.

## Getting Started (Firmware)

```bash
git clone https://github.com/adarsh-v-h/RL-ROVER.git
pip install -r requirements.txt
```

Open the `firmware/` folder directly in VS Code, PlatformIO auto-detects the
project from `platformio.ini`. Then either use the PlatformIO toolbar
(checkmark icon = build), or from the terminal:

```bash
cd firmware
pio run
```

This compiles the code into machine code for the ESP32, no physical board
needed for this step. A clean build with no errors means the toolchain is
correctly set up on your machine.

To flash it to a real board later (once you have one connected via USB):

```bash
pio run --target upload
```

To watch serial output from a connected board:

```bash
pio device monitor
```

## Getting Started (Brain / Backend) — once those folders exist

We are creating 2 separate containers, one is the backend of the Web Application and the other is the brain. <br>
To bring up the container of backend:
```bash
cd backend
docker build -t rover-backend .      
docker run --rm rover-backend
```
To bring up the container of the brain
```bash
cd brain    
docker build -t rover-brain . 
docker run --rm rover-brain
```
## Getting Started (Frontend) — 

```bash
cd frontend
npm install
npm run dev
```

## Contributing

- Don't commit `.pio/`, Python virtual envs, `node_modules/`, or recorded
  sensor/camera datasets, see `.gitignore`.
- Don't commit real WiFi credentials, copy `firmware/secrets.h.example` to
  `firmware/secrets.h` (gitignored) and fill in your own when testing against
  real hardware.
- Keep message/data schema changes (anything both firmware and backend depend
  on) documented in `/docs`, since both sides need to stay in sync.

## Team

Adarsh, Abhinav K, Rajasekhar, Hemachand