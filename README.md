# 🌌 Fract-ol
  ![Fractol Logo](fract-ole.png)
  
## 📌 Table of Contents
- [Introduction](#introduction)
- [Project Objectives](#project-objectives)
- [Supported Fractals](#supported-fractals)
- [Controls](#controls)
- [Compilation](#compilation)
- [Execution](#execution)
- [Examples](#examples)
- [Implementation Overview](#implementation-overview)
- [Resources](#resources)

---

## 🧩 Introduction

**Fract-ol** is a graphical project at 42 school that introduces you to the beauty of **fractals** while learning how to manipulate pixels, use the **MiniLibX** graphical library, and handle user input in a graphical window.

---

## 🎯 Project Objectives

- Learn to use **MiniLibX** to draw to a window.
- Work with complex numbers to generate fractals.
- Handle keyboard and mouse input for interactivity.
- Create a visually appealing and performant fractal explorer.
- Understand basic multithreading (bonus).

---

## 🌱 Supported Fractals

The program must render at least the following fractals:

- 🌀 **Mandelbrot**
- 🔮 **Julia**
- 🧿 **Burning Ship** (optional or bonus)

---

## 🎮 Controls

| Action               | Input                           |
|----------------------|----------------------------------|
| Zoom in/out          | Mouse scroll up/down             |
| Move view            | Arrow keys                       |
| Change color scheme  | `C` key                          |
| Reset view           | `R` key                          |
| Exit program         | `ESC` key                        |

For Julia:
- Mouse movement can influence the fractal shape (if implemented).
- Lock/unlock mouse interaction using a key (optional).

---

## 🛠 Compilation

To compile the project, use:

```bash
make
````

To clean object files:

```bash
make clean
```

To remove executable and objects:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

## 🚀 Execution

```bash
./fractol <name>
```

Where `<name>` is one of:

* `mandelbrot`
* `julia`
* `burningship` (if implemented)

Example:

```bash
./fractol mandelbrot
```

For Julia, you may pass extra parameters (depending on your implementation):

```bash
./fractol julia
```

---

## 🌠 Examples

**Mandelbrot Set**

```
./fractol mandelbrot
```

**Julia Set**

```
./fractol julia
```

**Burning Ship (Bonus)**

```
./fractol burningship
```

---

## 🧠 Implementation Overview

* **Complex Numbers**: Used to compute fractal equations.
* **MiniLibX**: Handles window, image buffer, events, and rendering.
* **Pixel Manipulation**: Directly coloring pixels in memory.
* **Zooming and Panning**: Mapping screen coordinates to the complex plane.
* **Performance**: Optimized drawing using iterations and escape time algorithm.

---

## 📚 Resources

* [Fractal Math](https://en.wikipedia.org/wiki/Mandelbrot_set)
* MiniLibX Documentation
* `man mlx_loop`, `man mlx_new_image`, `man mlx_put_image_to_window`
* [42 Docs – Fract-ol](https://harm-smits.github.io/42docs/projects/fract-ol)

---

> 🌌 Project developed as part of the 42 Network to explore the beauty of mathematics, graphics programming, and user interaction.
