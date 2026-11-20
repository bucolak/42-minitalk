_This project has been created as part of the 42 curriculum by bucolak._

# minitalk

A client–server program in **C** that sends text between two processes using only the UNIX signals **SIGUSR1** and **SIGUSR2**.

## How It Works

- The server starts and prints its PID.
- The client converts each character to bits and sends them one by one: `SIGUSR1` for 1, `SIGUSR2` for 0.
- The server rebuilds the bits into bytes with a `sigaction` handler and prints the message.
- **Bonus:** the server sends an acknowledgement signal back to the client (using `si_pid` from `siginfo_t`), and Unicode characters are supported because the message is sent byte by byte.

## Usage

```bash
make          # or: make bonus
./server      # prints PID
./client <server_pid> "Hello from minitalk!"
```

## Concepts Practised

UNIX signals · `sigaction` and `siginfo_t` · bitwise operations · inter-process communication

## Author

**Buket Çolak** (bucolak) — [github.com/bucolak](https://github.com/bucolak)
