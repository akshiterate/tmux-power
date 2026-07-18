# tmux-power

A lightweight, native battery status plugin for **tmux** written in modern C++.

Unlike many battery widgets that depend on external utilities such as `upower` or `acpi`, **tmux-power** reads battery information directly from the Linux kernel through `/sys/class/power_supply`.

This makes it extremely lightweight, fast, and portable across most Linux distributions.

## Preview
<img width="1456" height="32" alt="image" src="https://github.com/user-attachments/assets/8b29ed34-74b3-4ec5-b925-1dd6b44120f0" />
```
BAT:79%[DCHG]
BAT:54%[CHG]
BAT:100%[FULL]
BAT:80%[NCHG]
```

---

## Requirements

- Linux
- tmux
- A battery exposed through `/sys/class/power_supply`

No additional packages such as:

- `upower`
- `acpi`
- Python
- Shell scripts
- GUI libraries

are required.

---

## Compatibility

| Platform | Status |
|----------|--------|
| Linux x86_64 | Supported |
| Linux ARM64 | Build from source |
| Android (Termux) | Likely supported if `/sys/class/power_supply` is accessible (requires ARM64 build) |
| macOS | Not supported |
| Windows | Not supported |

---

# Installation

## Method 1 — TPM (Recommended)

Add the plugin to your `~/.tmux.conf`:

```tmux
set -g @plugin 'YOUR_USERNAME/tmux-power'
```

Initialize TPM if you haven't already:

```tmux
run '~/.tmux/plugins/tpm/tpm'
```

Reload tmux and install plugins:

```
Prefix + I
```

Restart tmux or reload your configuration.

---

## Method 2 — Download Prebuilt Binary

Download the latest **x86_64** binary from the Releases page.

Make it executable:

```bash
chmod +x tmux-power-linux-x86_64
```

Add it to your `~/.tmux.conf`:

```tmux
set -ag status-right " #(~/path/to/tmux-power-linux-x86_64)"
```

Reload tmux:

```bash
tmux source-file ~/.tmux.conf
```

---

## Method 3 — Build From Source

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/tmux-power.git
cd tmux-power
```

Compile:

```bash
mkdir -p bin

g++ -std=c++17 -O2 src/main.cpp -o bin/tmux-power
```

Add the binary to your status bar:

```tmux
set -ag status-right " #($HOME/path/to/tmux-power/bin/tmux-power)"
```

Reload tmux:

```bash
tmux source-file ~/.tmux.conf
```

---

# Output

Possible outputs:

```
BAT:84%[DCHG]
BAT:58%[CHG]
BAT:100%[FULL]
```

---

# How it Works

`tmux-power` scans Linux's battery interface located at:

```
/sys/class/power_supply
```

It automatically detects the battery device and reads:

- `capacity`
- `status`


---

# License

MIT
