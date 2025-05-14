
# SecureSensorNode

A secure and modular embedded sensing system for pressure and temperature measurement, based on STM32 and integrated with a Python microservice backend.

---

## 📦 Project Structure

```
SecureSensorNode/
├── client/         # Embedded firmware (STM32CubeIDE project)
│   └── firmware/   # Core STM32 code (Core/, Drivers/, startup/, etc.)
├── server/         # Python microservice exposing REST API (WIP)
├── docs/           # Technical documentation (Markdown-based)
│   └── SecureSensorNode_Report.md
└── README.md       # You are here
```

---

## ⚙️ Technologies

- **STM32F401RE** – 32-bit ARM Cortex-M4 MCU
- **STM32CubeIDE** – HAL libraries, code generation, project build
- **CMSIS** – low-level ARM register definitions
- **Python 3.x** – backend service (to be integrated)
- **Git** – version control and collaboration
- **Markdown** – project documentation

---

## 🚀 First Milestone Achieved

✅ Successful deployment of a blinking LED using HAL and SysTick  
✅ Flashing verified with `st-flash` from CLI  
✅ HAL vs CMSIS abstraction documented in detail

---

## 📄 Documentation

All technical documentation is stored in the [`docs/`](./docs) folder.  
The full report is available in:

```
docs/SecureSensorNode_Report.md
```

It includes:
- Project overview and goals
- Development environment
- Code structure
- HAL vs CMSIS deep-dive
- First test and result analysis

---

## 📍 Next Steps

- Integrate BME280 sensor (I2C)
- Add AES/SHA256 embedded encryption
- Implement and test Python microservice
- Evaluate CI/CD pipeline for flashing and testing

---

