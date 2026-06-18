<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:050505,28:17130A,55:D4AF37,78:7A5200,100:050505&height=290&section=header&text=SAMP%20MOBILE%202.11.311&fontSize=48&fontColor=FFF3C4&animation=fadeIn&fontAlignY=35&desc=BLACK%20%2F%20GOLD%20CYBERPUNK%20SOURCE%20CONTINUATION&descAlignY=56&descSize=16" width="100%" alt="SAMP Mobile 2.11.311 black and gold cyberpunk header">
</p>

<p align="center">
  <a href="#english"><img src="https://img.shields.io/badge/ENGLISH-080808?style=for-the-badge&logo=readme&logoColor=FFD65A&labelColor=080808" alt="English"></a>
  <a href="#ภาษาไทย"><img src="https://img.shields.io/badge/ภาษาไทย-D4AF37?style=for-the-badge&logo=readme&logoColor=080808&labelColor=D4AF37" alt="ภาษาไทย"></a>
  <a href="#build--การ-build"><img src="https://img.shields.io/badge/BUILD-151008?style=for-the-badge&logo=gradle&logoColor=FFD65A" alt="Build"></a>
  <a href="#credits--เครดิต"><img src="https://img.shields.io/badge/CREDITS-2A1C00?style=for-the-badge&logo=github&logoColor=FFD65A" alt="Credits"></a>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/STATUS-EXPERIMENTAL-D4AF37?style=flat-square&labelColor=080808" alt="Experimental">
  <img src="https://img.shields.io/badge/GTA-2.11.311-FFB000?style=flat-square&labelColor=080808" alt="GTA 2.11.311">
  <img src="https://img.shields.io/badge/ABI-arm64--v8a-FFD65A?style=flat-square&labelColor=080808" alt="arm64-v8a">
  <img src="https://img.shields.io/badge/AI-ASSISTED-8A6500?style=flat-square&labelColor=080808" alt="AI-assisted">
</p>

<p align="center">
  <b>Android · Java · JNI · C++ · CMake · Gradle</b><br>
  <sub>An unofficial research and development continuation—not a production release.</sub>
</p>

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=rect&color=0:050505,25:D4AF37,50:FFF3C4,75:D4AF37,100:050505&height=4" width="100%" alt="Gold divider">
</p>

> [!IMPORTANT]
> **Verified continuation boundary:** branch [`xdatsec/GTA_2.11.311:XS`](https://github.com/xdatsec/GTA_2.11.311/commits/XS/) ends at [`c7266cf`](https://github.com/xdatsec/GTA_2.11.311/commit/c7266cf5f8f1e3216fa51b289d238baf7d4ded49), while its final code-changing commit is [`a488cd5`](https://github.com/xdatsec/GTA_2.11.311/commit/a488cd5cc5d60bf4d62a53822ba516d559af3900). JohnPeriaX imported a reorganized snapshot as [`54eef844`](https://github.com/JohnPeriaX/samp-mobile-2.11.311/commit/54eef844e7b1ee48c8530855b695ebe8d67d0201) and began committed continuation work at [`ab5e026f`](https://github.com/JohnPeriaX/samp-mobile-2.11.311/commit/ab5e026f3823bc6c7ca614fd86c7a2098e6b38ae). The two repositories do not share preserved parent history, so these checkpoints describe provenance without claiming an exact Git fork relationship.

---

<a id="english"></a>

# English

## Project overview

**SAMP Mobile 2.11.311** is an Android source snapshot and an ongoing technical continuation for **GTA: San Andreas Mobile 2.11 / SAMP Mobile**. It contains the Android launcher, Java runtime layer, JNI bridge, native C++ game/SAMP systems, resources, assets, and native dependencies required for research and further development.

This repository is unofficial, experimental, and unfinished. It should be used as a development reference—not as a verified production-ready release.

## Source lineage and ownership boundary

The repository deliberately separates the imported baseline from later work:

| Layer | Evidence boundary | Attribution |
| --- | --- | --- |
| Upstream code baseline | `xdatsec/XS` through `a488cd5` | Code development by **xdatsec / CYBERX** and earlier contributors |
| Upstream branch tip | `c7266cf` | Final `XS` checkpoint; commits after `a488cd5` update README, credits, and disclaimer only |
| Local import checkpoint | `54eef844` | Reorganized snapshot imported into this repository by **JohnPeriaX**; not an ancestry-preserving fork commit |
| Continued development | `ab5e026f` and later | Directed and maintained by **JohnPeriaX**, with AI-assisted implementation and review |
| Third-party components | Vendor libraries, GTA-related interfaces, assets, and external dependencies | Remain the property/work of their respective authors and rights holders |

### How far the xdatsec `XS` branch progressed

The public `XS` history shows the following upstream scope before this continuation:

| Upstream checkpoint | Recorded progress |
| --- | --- |
| `6d255cc` → `31d9878` | Initial Android project work, storage/downloader changes, GTA 2.11.311 setup, and merge with the Kurdish Roleplay base |
| `7eb1b83` | Partial migration to GTA 2.11.311 |
| `c04870c` → `c5422f3` | CStreaming/intro, crash, fire-instant-hit, and related investigation; some items remained explicitly marked TODO |
| `f8068cd` | Reduced active pools to vehicle/player at that stage |
| `91a2567` → `5b171b6` | Weapon-audio investigation plus matrix and RakNet crash work; some matrix work still required verification |
| `a4bafeb` | Static-matrix allocation crash investigation remained marked for checking |
| `cf46976` | FPS patch |
| `a488cd5` | Reloading bug fix—the last code-changing commit on `XS` |
| `cb940b0` → `c7266cf` | README, source clarification, credits, and disclaimer updates only |

At that point the source already included the Android/Gradle project, Java runtime wrappers, JNI/CMake integration, native C++ SAMP/game framework, networking, GUI, hooks, selected pools, vendor code, native libraries, and assets. The upstream history also documents unfinished or verification-required areas; this README does not present those TODO items as completed fixes.

These foundations are **not claimed as original JohnPeriaX work**. They remain credited to the upstream source lineage and their respective contributors.

### Where the JohnPeriaX continuation begins

The source was imported and reorganized in local checkpoint `54eef844`. The first committed continuation change is `ab5e026f` (`feat(3dtext): add PC-like 3DText label system`). Verified work after that point includes:

- Added and stabilized PC-like **3D text label**, **pickup**, **actor**, and **menu pool** lifecycles
- Refactored the legacy FPS path and improved frame pacing with display refresh-rate awareness
- Fixed far-distance remote-ped visibility
- Removed obsolete 32-bit native paths and aligned active native work with **GTA 2.11 arm64**
- Preserved SA-MP authentication word behavior on arm64
- Reworked building-removal matching, object draw distance, forced rendering, camera hooks, and renderer behavior
- Updated GTA 2.11.311 Java wrappers, application metadata, lifecycle handling, and touch-slot stability
- Hardened HUD polling/input behavior and handled unavailable Firebase update configuration
- Improved 2.11 patch organization, repository documentation, and Git hygiene

This list describes committed continuation work only. It does not transfer ownership of the imported baseline or third-party code to JohnPeriaX.

## Development status

| Area | Status | Notes |
| --- | :---: | --- |
| Android launcher | Present | Experimental launcher/runtime integration |
| Java / JNI bridge | Active | Continued alignment with GTA 2.11.311 |
| Native C++ core | Active | arm64-oriented hooks, patches, pools, and renderer work |
| Multiplayer systems | In progress | Several systems exist but still require runtime validation |
| Production release | Not ready | Bugs, crashes, incomplete paths, and device-specific issues may remain |

## AI-assisted development notice

JohnPeriaX is the repository owner, project operator, and development director. Prompts, requirements, test evidence, and technical direction are provided by JohnPeriaX; AI tools may assist with analysis, implementation, refactoring, documentation, commits, and validation.

AI-assisted changes can still contain incorrect assumptions, incomplete logic, security issues, or runtime regressions. Review and test all important changes before use or redistribution.

## Technical profile

| Item | Current value |
| --- | --- |
| Package namespace | `com.kurdish.roleplay` |
| Minimum SDK | `28` |
| Target / Compile SDK | `36` / `36` |
| NDK | `26.2.11394342` |
| Native build | CMake through Gradle |
| Active ABI | `arm64-v8a` |
| Project state | Experimental research snapshot |

## Repository structure

```text
.
├── app/src/main/
│   ├── assets/       Game and launcher assets
│   ├── cpp/          JNI, native C++, SAMP, hooks, and vendor code
│   ├── java/         Android launcher and game runtime code
│   ├── jniLibs/      Native binary dependencies
│   └── res/          Android resources
├── gradle/           Gradle wrapper
├── build.gradle      Root build configuration
├── settings.gradle   Android project settings
└── README.md
```

## Known limitations

- Runtime behavior has not been validated on every Android device or OS version
- Some hooks and patches may still be incomplete or version-sensitive
- Native crashes, visual issues, and multiplayer incompatibilities may remain
- Included third-party/native material must be reviewed before redistribution
- No production-readiness or compatibility guarantee is provided

---

<a id="ภาษาไทย"></a>

# ภาษาไทย

## ภาพรวมโปรเจกต์

**SAMP Mobile 2.11.311** เป็น source snapshot และโปรเจกต์พัฒนาต่อยอดเชิงเทคนิคสำหรับ **GTA: San Andreas Mobile 2.11 / SAMP Mobile** บน Android ภายในประกอบด้วย Android launcher, Java runtime, JNI bridge, native C++ game/SAMP systems, resources, assets และ native dependencies สำหรับการศึกษาและพัฒนาต่อ

Repository นี้เป็นโปรเจกต์ไม่เป็นทางการ อยู่ในสถานะทดลองและยังไม่สมบูรณ์ ควรใช้เป็นแหล่งอ้างอิงสำหรับการพัฒนา ไม่ใช่ release ที่ยืนยันว่าพร้อมใช้งานจริง

## ที่มาของ Source และเส้นแบ่งผลงาน

Repository นี้แยก source ต้นฉบับกับงานพัฒนาต่ออย่างชัดเจน:

| ส่วนงาน | เส้นแบ่งที่ตรวจสอบได้ | เครดิต |
| --- | --- | --- |
| Code baseline ต้นฉบับ | `xdatsec/XS` ถึง `a488cd5` | งานพัฒนา code โดย **xdatsec / CYBERX** และผู้มีส่วนร่วมก่อนหน้า |
| จุดสิ้นสุด branch ต้นฉบับ | `c7266cf` | Commit ล่าสุดของ `XS`; หลัง `a488cd5` เปลี่ยนเฉพาะ README, credits และ disclaimer |
| จุดนำเข้าใน repository นี้ | `54eef844` | **JohnPeriaX** นำ snapshot ที่จัดโครงสร้างใหม่เข้ามา โดยไม่ได้รักษา parent history แบบ Git fork |
| งานพัฒนาต่อ | `ab5e026f` เป็นต้นไป | ควบคุมทิศทางและดูแลโดย **JohnPeriaX** พร้อมกระบวนการพัฒนาแบบ AI-assisted |
| Third-party | Vendor libraries, GTA interfaces, assets และ dependencies ภายนอก | เป็นผลงานหรือทรัพย์สินของผู้สร้างและผู้ถือสิทธิ์แต่ละราย |

### xdatsec พัฒนาถึงจุดไหน

จาก public history ของ branch `XS` ขอบเขตงานต้นฉบับก่อนนำมาต่อยอดมีดังนี้:

| Upstream checkpoint | งานที่บันทึกไว้ |
| --- | --- |
| `6d255cc` → `31d9878` | เริ่ม Android project, ปรับ storage/downloader, ตั้งค่า GTA 2.11.311 และ merge กับฐาน Kurdish Roleplay |
| `7eb1b83` | ย้ายระบบไป GTA 2.11.311 บางส่วน ยังไม่ใช่ migration ที่สมบูรณ์ |
| `c04870c` → `c5422f3` | งาน CStreaming/intro, crash, fire-instant-hit และการตรวจหาปัญหาที่เกี่ยวข้อง โดยบางรายการยังระบุ TODO ไว้ชัดเจน |
| `f8068cd` | ลด pool ที่ใช้งานในช่วงนั้นให้เหลือ vehicle/player |
| `91a2567` → `5b171b6` | ตรวจปัญหาเสียงอาวุธ และแก้ matrix/RakNet crash โดย matrix บางส่วนยังต้องตรวจสอบต่อ |
| `a4bafeb` | งานตรวจ crash ของ static-matrix allocation ยังระบุว่าต้องตรวจสอบ |
| `cf46976` | เพิ่ม FPS patch |
| `a488cd5` | แก้ reloading bug และเป็น commit สุดท้ายของ branch `XS` ที่เปลี่ยน code |
| `cb940b0` → `c7266cf` | ปรับ README, ชี้แจงที่มา source, credits และ disclaimer เท่านั้น |

ณ จุดนั้น source มีโครงสร้าง Android/Gradle, Java runtime wrappers, JNI/CMake, native C++ SAMP/game framework, networking, GUI, hooks, pools บางส่วน, vendor code, native libraries และ assets อยู่แล้ว และยังมีงาน TODO หรือส่วนที่ต้องตรวจสอบตาม commit history จึงไม่ควรนับส่วนเหล่านั้นว่า xdatsec ทำเสร็จสมบูรณ์แล้ว

ส่วนพื้นฐานเหล่านี้ **ไม่ถูกอ้างว่าเป็นผลงานต้นฉบับของ JohnPeriaX** และยังคงเครดิตให้ upstream source กับผู้มีส่วนร่วมเดิมตามหลักฐานที่มี

### งานของ JohnPeriaX เริ่มจากตรงไหน

Source ถูกนำเข้าและจัดโครงสร้างใหม่ที่ checkpoint `54eef844` ส่วน code งานต่อยอด commit แรกคือ `ab5e026f` (`feat(3dtext): add PC-like 3DText label system`) หลังจากนั้นจึงมีงานที่ตรวจสอบได้ดังนี้:

- เพิ่มและปรับเสถียรภาพระบบ **3D text label**, **pickup**, **actor** และ **menu pool** ให้มี lifecycle ใกล้เคียง PC
- Refactor ระบบ FPS เดิม ปรับ frame pacing และตรวจ refresh rate ของหน้าจอ
- แก้ปัญหา remote ped หายเมื่ออยู่ระยะไกล
- ถอด native path แบบ 32-bit ที่ไม่เหมาะกับเวอร์ชันนี้ และปรับงานหลักให้ตรงกับ **GTA 2.11 arm64**
- รักษาพฤติกรรม SA-MP authentication word บน arm64
- ปรับระบบลบสิ่งปลูกสร้าง ระยะวาด object การบังคับ render camera hooks และ renderer
- ปรับ Java wrappers, application metadata, lifecycle และ touch slot ให้เข้ากับ GTA 2.11.311
- ป้องกัน HUD polling/input ที่ไม่ถูกต้อง และรองรับกรณี Firebase update configuration ใช้งานไม่ได้
- จัดระเบียบ 2.11 patches, เอกสาร repository และ Git hygiene

รายการนี้กล่าวถึงเฉพาะงานต่อยอดที่ commit แล้ว ไม่ได้โอนเครดิตหรือความเป็นเจ้าของ source ต้นฉบับและ third-party code มาเป็นของ JohnPeriaX

## สถานะการพัฒนา

| ส่วน | สถานะ | หมายเหตุ |
| --- | :---: | --- |
| Android launcher | มีอยู่ | การเชื่อมต่อ launcher/runtime ยังอยู่ในขั้นทดลอง |
| Java / JNI bridge | กำลังพัฒนา | ปรับให้ตรงกับ GTA 2.11.311 ต่อเนื่อง |
| Native C++ core | กำลังพัฒนา | เน้น arm64, hooks, patches, pools และ renderer |
| Multiplayer systems | ยังไม่สมบูรณ์ | หลายระบบมีอยู่แล้วแต่ยังต้องทดสอบ runtime |
| Production release | ยังไม่พร้อม | อาจยังมี bug, crash และปัญหาเฉพาะอุปกรณ์ |

## ประกาศการพัฒนาแบบ AI-assisted

**JohnPeriaX** เป็นเจ้าของ repository ผู้ควบคุมโปรเจกต์และกำหนดทิศทางการพัฒนา โดยเป็นผู้ให้ prompt, requirement, หลักฐานการทดสอบ และแนวทางทางเทคนิค ส่วน AI tools อาจช่วยวิเคราะห์ เขียนหรือแก้ code, refactor, จัดทำเอกสาร, commit และตรวจสอบผลลัพธ์

งานที่พัฒนาด้วย AI อาจมี assumption ผิด logic ไม่ครบ ปัญหาด้านความปลอดภัย หรือ runtime regression ผู้ใช้ควร review และทดสอบส่วนสำคัญทั้งหมดก่อนนำไปใช้หรือแจกจ่ายต่อ

## ข้อมูลทางเทคนิค

| รายการ | ค่าปัจจุบัน |
| --- | --- |
| Package namespace | `com.kurdish.roleplay` |
| Minimum SDK | `28` |
| Target / Compile SDK | `36` / `36` |
| NDK | `26.2.11394342` |
| Native build | CMake ผ่าน Gradle |
| ABI ที่ใช้งาน | `arm64-v8a` |
| สถานะโปรเจกต์ | Experimental research snapshot |

## โครงสร้าง Repository

```text
.
├── app/src/main/
│   ├── assets/       Asset ของเกมและ launcher
│   ├── cpp/          JNI, native C++, SAMP, hooks และ vendor code
│   ├── java/         Android launcher และ game runtime code
│   ├── jniLibs/      Native binary dependencies
│   └── res/          Android resources
├── gradle/           Gradle wrapper
├── build.gradle      Root build configuration
├── settings.gradle   Android project settings
└── README.md
```

## ข้อจำกัดที่ควรทราบ

- ยังไม่ได้ยืนยัน runtime ครบทุกอุปกรณ์และ Android ทุกเวอร์ชัน
- Hooks และ patches บางส่วนอาจยังไม่ครบหรือขึ้นอยู่กับ game version
- อาจยังมี native crash, ปัญหาภาพ และ multiplayer incompatibility
- ต้องตรวจสอบสิทธิ์ของ third-party/native material ก่อนนำไปแจกจ่าย
- ไม่มีการรับประกันความพร้อมใช้งานจริงหรือความเข้ากันได้

---

<a id="build--การ-build"></a>

# Build / การ Build

Run from the repository root / รันจาก root ของ repository:

```powershell
.\gradlew.bat assembleDebug --no-daemon
```

For native-only validation / สำหรับตรวจสอบ native code โดยตรง:

```powershell
.\gradlew.bat ':app:buildCMakeDebug[arm64-v8a]' --no-daemon --console=plain
```

Recommended environment / สภาพแวดล้อมที่แนะนำ:

```text
Android Studio
Android SDK Platform 36
Android NDK 26.2.11394342
CMake from Android SDK tools
Compatible JDK
```

---

<a id="credits--เครดิต"></a>

# Credits / เครดิต

| Name | Credit preserved for |
| --- | --- |
| **Rockstar Games** | GTA: San Andreas and related trademarks, assets, interfaces, and intellectual property |
| **xdatsec / CYBERX** | Upstream `XS` development through code commit `a488cd5` and branch checkpoint `c7266cf` |
| **Alyn SAMP** | Legacy SAMP Mobile credit preserved from the imported source |
| **x1y2z** | Legacy/native GTA-reversed work explicitly credited in source comments |
| **Other contributors** | Vendor libraries, dependencies, research, and source work retained in this repository |
| **JohnPeriaX** | Snapshot import/reorganization at `54eef844`; project direction, maintenance, and committed continuation beginning at `ab5e026f` |
| **AI-assisted workflow** | Analysis and implementation support under JohnPeriaX's requirements and review |

> [!NOTE]
> If a contributor or source attribution is incomplete, open an issue with verifiable evidence. The goal is to correct and preserve credit—not to remove or replace legitimate ownership.

---

# Disclaimer / ข้อจำกัดความรับผิดชอบ

> [!CAUTION]
> Grand Theft Auto: San Andreas, its original assets, trademarks, logos, and related intellectual property belong to **Rockstar Games** and their respective rights holders.

This repository does not claim ownership of Rockstar Games material, the imported upstream baseline, or third-party dependencies. No license file is currently provided by this repository; do not assume permission to redistribute protected material solely because it is present here.

Repository นี้ไม่ได้อ้างสิทธิ์ใน material ของ Rockstar Games, source ต้นฉบับที่นำเข้ามา หรือ third-party dependencies และปัจจุบัน repository ไม่มีไฟล์ license จึงไม่ควรตีความว่าการมีไฟล์อยู่ใน repository เท่ากับได้รับอนุญาตให้นำ material ที่มีลิขสิทธิ์ไปแจกจ่ายต่อ

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=0:050505,28:7A5200,55:D4AF37,78:17130A,100:050505&height=170&section=footer" width="100%" alt="Black and gold cyberpunk footer">
</p>
