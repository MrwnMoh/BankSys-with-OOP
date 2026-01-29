# 🏦 BankSys OOP

A **high-performance console-based Bank Management System** developed using **C++**, demonstrating **Object-Oriented Programming (OOP)** with a focus on **Advanced Data Security**, **User Authorization**, and a **Rich Visual Experience**.

---

## 🎨 Immersive User Interface (Full Color Support)

Unlike standard black-and-white console apps, this system features a **Full Color-Coded Interface** for better usability and aesthetics:

- **Dynamic Permissions Rendering:** Main menu intelligently changes colors to indicate accessible or locked features based on your permission level.
- **Status Indicators:** Success messages, errors, and warnings are distinctively colored (Green/Red/Yellow) for instant visual feedback.
- **Modern Terminal Dashboard:** Modular dashboard design with colored headers and formatted tables for clear client data visualization.

---

## 🛡️ Exclusive Security & User Control

- **5-Layer Encryption Engine:** Custom cryptographic process including Key Cipher, Padding, Case Inversion, Nested Encryption, and Hex Encoding.
- **Permissions Management:** Dedicated list to control access levels (Admin/User) for every module.
- **Refresh Users Security:** Re-encrypts all user passwords in the database to maintain high-level protection.
- **Activity Log System (Audit Trail):** Every action (add client, view data, transactions) is automatically logged with a timestamp.

---

## 🚀 Key Features

- **Client Management:** Full CRUD system (Add, Find, Update, Delete) with persistent storage.
- **Transactions Module:** Secure Deposit, Withdraw, and Transfer operations with real-time balance validation.
- **Input Validation:** Prevents invalid entries and system crashes with robust sanitization.
- **Data Persistence:** Ensures all bank records, logs, and user data are securely saved.

---

## 💻 Technical Implementation (Encryption Logic)

```cpp
// Core 5-layer encryption logic
string Encrypted = _EncryptText(
    _InvertTextCase(
        _AddRandomPadding(
            _EncryptText(Text, Key), Key
        )
    ), Key
);
return TextToHex(Encrypted);
