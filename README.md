# RISC-Vマイコン CH32V203評価F/W開発
WCH製 RISC-Vマイコン CH32V203の評価F/W個人開発リポジトリ

## 開発環境

### H/W

- 評価基板
  - `CH32Vx03C-R0-1V0`

- マイコン ... 型番:[CH32V203K8T6](https://akizukidenshi.com/catalog/g/g118063/)🔗
  - CPU ... [QingKeV4B (32bit RISC-V RV32IMAC)](https://www.wch-ic.com/downloads/QingKeV4_Processor_Manual_PDF.html)🔗
  - ROM ... 64KB
  - RAM ... 20KB
  - Clock ... 144MHz
  - GPIO ... 26本
  - DMA ... x8ch
  - I2C ... x1ch
  - SPI ... x1ch
  - UART ... x2ch
  - CAN
  - ADC ... 12bit SAR x10ch
  - タイマー ... 16bit x4本
  - SysTick ... 64bit
  - WDT ... x2ch
  - RTC
  - USB

### S/W

- IDE/SDK/コンパイラ
  - [MounRiver Studio (MRS) V2.20](https://www.mounriver.com/download)🔗

### デバッガ

- [WCH-LinkE Ver1.3](https://akizukidenshi.com/catalog/g/g118065)🔗

### デバッグ

デバッグ ... `SDI` (2-wire serial debug interface)

#### SDI

- [WCH-LinkE <--> 評価基板]
  - SWDIO <--> PD1ピン
  - GND <--> GND

#### UART

- [WCH-LinkE <--> 評価基板]
  - RX <--> PA9ピン(TX)
  - TX <--> PA10ピン(RX)
  - GND <--> GND
