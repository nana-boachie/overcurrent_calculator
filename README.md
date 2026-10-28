# Overcurrent Calculator

A command-line calculator for inverse-time overcurrent (IDMT) relay trip times, written in C. Enter the relay's pickup current, the fault current and the time multiplier, pick a curve, and it prints how long the relay takes to trip.

Useful for quick protection coordination checks without opening a full study tool.

## Supported curves

**IEC 60255** — `t = TMS × k / ((I / Is)^α − 1)`

| Curve | k | α |
| --- | --- | --- |
| Standard Inverse | 0.14 | 0.02 |
| Very Inverse | 13.5 | 1 |
| Extremely Inverse | 80 | 2 |
| Long Time Standard Inverse | 120 | 1 |

**IEEE C37.112** — `t = TD × (A / ((I / Is)^p − 1) + B)`

| Curve | A | B | p |
| --- | --- | --- | --- |
| Moderately Inverse | 0.0515 | 0.114 | 0.02 |
| Very Inverse | 19.61 | 0.491 | 2 |
| Extremely Inverse | 28.2 | 0.1217 | 2 |

`I` is the fault current, `Is` the pickup current, and `TMS`/`TD` the time multiplier or time dial. If the fault current is at or below pickup, the relay doesn't trip and the calculator says so.

## Build

Requires a C99 compiler and `make`:

```bash
make
```

Without `make`:

```bash
gcc -std=c99 main.c overcurrent_calculator.c -o overcurrent_calculator -lm
```

## Usage

```bash
./overcurrent_calculator
```

Example: a 1,000 A fault on a relay with a 100 A pickup, TMS 0.1, IEC Standard Inverse:

```text
Overcurrent Protection Trip Time Calculator
========================================
Select Curve Standard:
Select Curve Standard (20 for IEC, 30 for IEEE): 20
Enter Pickup Current (A): 100
Enter Fault Current (A): 1000
Enter Time Multiplier Setting: 0.1
Select IEC Curve Type (0: Inverse, 1: Very Inverse, 2: Extremely Inverse, 3: Long Time Standard Inverse): 0
Calculating trip time for IEC standard...
Pickup Current: 100.00 A, Fault Current: 1000.00 A, Time Multiplier Setting: 0.10
Trip time (Inverse): 0.30 seconds
```

## Author

Built by [Nana Kwame Yiadom Boachie](https://nana-boachie.github.io/my_portfolio/), power systems protection engineer.
