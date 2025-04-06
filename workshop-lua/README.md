
# 🛩️ Lua Scripting in ArduPilot – Quickstart Guide

Welcome to this brief and practical introduction to using **Lua scripts** with **ArduPilot**!  
This guide is based on internal workshops from the Skyrats team and focuses on essential concepts, setup, and real-use examples for onboard drone logic using Lua.

---

## 🧠 What is Lua in ArduPilot?

**Lua scripting** allows developers to extend the logic of ArduPilot vehicles with custom behavior **without modifying the firmware**. Scripts run onboard, making it easier to:

- Implement **safety mechanisms** (e.g., geofences or time-based failsafes)
- Add custom **mission logic**
- Perform **onboard monitoring** and telemetry customization

> Lua support is available for boards with enough memory, like **Pixhawk 2.4.8**, **CubeOrange**, **Durandal**, etc.

---

## ⚙️ Prerequisites

To use Lua scripting with ArduPilot:

1. Use **ArduPilot firmware v4.0 or newer**
2. Set the following parameters via Mission Planner or equivalent GCS:
    ```text
    SCR_ENABLE = 1         # Enables Lua scripting
    SCR_HEAP_SIZE = 2000   # Memory available to scripts (adjust for your board)
    ```
3. Create the following folder on the SD card:
    ```
    APM/scripts/
    ```
4. Place your `.lua` script(s) in that folder.

---

## 📝 Writing Your First Lua Script

Here's a minimal example that sends a message to the GCS every second:

```lua
function update()
    gcs:send_text(6, "Hello from Lua!")
    return update, 1000  -- Repeat every 1000ms
end

return update()
```

Save this as `hello.lua` in the `APM/scripts/` folder.

---

## 📂 Script Lifecycle and Debugging

- Scripts are **automatically loaded** when the vehicle boots.
- Output messages can be viewed in **Mission Planner’s Messages tab** or via MAVProxy.
- To disable a script, either remove the file or rename it (e.g., `hello.lua.bak`).

---

## 📦 Useful APIs

Lua in ArduPilot provides access to many vehicle functions and telemetry. A few examples:

- `gcs:send_text(severity, message)` — send message to GCS
- `vehicle:get_mode()` — get current flight mode
- `arming:is_armed()` — check if vehicle is armed
- `SRV_Channels:set_output_pwm(channel, pwm)` — set PWM output on a servo channel

Check [ArduPilot’s Lua API Reference](https://ardupilot.org/copter/docs/common-lua-scripts.html) for more.

---

## 💡 Example Use Cases

- Trigger RTL after X minutes in air
- Disable motors if drone crosses custom geofence
- Perform autonomous servo sequences in flight
- Add custom GCS messages for debugging

---

## 🧪 Skyrats Lua Scripts (Outdoor IMAV 2024)

Our scripts for safety and mission logic (geofencing, failsafes, etc.) are available here:

📁 [SkyRats/sky_mission – OUTDOOR-2024](https://github.com/SkyRats/sky_mission/tree/OUTDOOR-2024)

---

## 🙌 Contributors

- Skyrats Drone Team @ USP
- Based on internal Lua scripting workshop materials

---
