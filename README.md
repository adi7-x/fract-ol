<p align="center">
  <img src="https://img.shields.io/badge/Score-125%2F100-brightgreen?style=for-the-badge" />
    <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" />
      <img src="https://img.shields.io/badge/42_Network-000000?style=for-the-badge&logo=42&logoColor=white" />
        <img src="https://img.shields.io/badge/MiniLibX-Graphics-orange?style=for-the-badge" />
        </p>

        <h1 align="center"> Fract-ol</h1>

        <p align="center">
          <i>The beauty of mathematics rendered pixel by pixel.</i>
            <br><br>
              A real-time fractal exploration engine built with <b>MiniLibX</b>.<br>
                Renders Mandelbrot, Julia, and Burning Ship sets with<br>
                  smooth coloring, infinite zoom, and interactive navigation.
                  </p>

                  ---

                  ##  Table of Contents

                  - [About](#-about)
                  - [Supported Fractals](#-supported-fractals)
                  - [The Mathematics](#-the-mathematics)
                  - [Controls](#-controls)
                  - [Color Schemes](#-color-schemes)
                  - [Getting Started](#-getting-started)
                  - [Usage Examples](#-usage-examples)
                  - [Technical Details](#-technical-details)
                  - [Screenshots](#-screenshots)
                  - [Author](#-author)

                  ---

                  ## About

                  **Fract-ol** is a graphical project from the 42 common core that introduces computer graphics programming through fractal rendering. The project requires:

                  - Pixel-level rendering using the **MiniLibX** graphics library
                  - Complex number mathematics for fractal computation
                  - Real-time interaction with keyboard and mouse input
                  - Color mapping and smooth gradient algorithms
                  - Efficient rendering for responsive zoom and navigation

                  ---

                  ## Supported Fractals

                  ### Mandelbrot Set

                  The Mandelbrot set is defined as the set of complex numbers `c` for which the iteration `z = z^2 + c` (starting from `z = 0`) does **not** diverge.

                  ### Julia Set

                  Julia sets use the same formula `z = z^2 + c`, but `c` is **fixed** and `z` starts as the pixel coordinate. Different values of `c` produce dramatically different patterns.

                  ### Burning Ship

                  A variant where absolute values are applied to the real and imaginary parts before squaring: `z = (|Re(z)| + i|Im(z)|)^2 + c`. Produces a characteristic ship-hull shape.

                  ---

                  ## The Mathematics

                  All three fractals share the same core iteration:

                  ```
                  For each pixel (px, py) on screen:

                      1. Map pixel to complex plane:
                           x = x_min + px * (x_max - x_min) / WIDTH
                                y = y_min + py * (y_max - y_min) / HEIGHT

                                  2. Iterate:
                                       Mandelbrot:  z(n+1) = z(n)^2 + c     where c = (x, y), z(0) = 0
                                            Julia:       z(n+1) = z(n)^2 + c     where z(0) = (x, y), c = constant
                                                 Burning Ship: z(n+1) = (|Re| + i|Im|)^2 + c

                                                   3. If |z| > 2.0 -> escaped -> color based on iteration count
                                                        If max_iterations reached -> inside the set -> color black
                                                        ```

                                                        ### Smooth Coloring

                                                        Instead of using raw iteration counts (which produce banding), the implementation uses **smooth coloring**:

                                                        ```c
                                                        // Smooth iteration count for gradient coloring
                                                        double smooth_iter = iter + 1.0 - log(log(sqrt(zr*zr + zi*zi))) / log(2.0);
                                                        ```

                                                        ---

                                                        ## Controls

                                                        | Input | Action |
                                                        |:------|:-------|
                                                        | `Scroll Up` | Zoom in (toward cursor) |
                                                        | `Scroll Down` | Zoom out |
                                                        | `Arrow Keys` | Pan the view |
                                                        | `+` / `-` | Increase / decrease max iterations |
                                                        | `C` | Cycle color schemes |
                                                        | `R` | Reset to default view |
                                                        | `ESC` | Close the window |
                                                        | `Mouse Click` | Set Julia parameter (in Julia mode) |

                                                        ---

                                                        ## Color Schemes

                                                        Multiple color palettes available, cycled with the `C` key:

                                                        | Scheme | Description |
                                                        |:-------|:------------|
                                                        | **Psychedelic** | Rainbow HSV rotation based on iteration |
                                                        | **Fire** | Black -> Red -> Orange -> Yellow -> White |
                                                        | **Ocean** | Deep blue -> Cyan -> White gradient |
                                                        | **Monochrome** | Black -> White grayscale |
                                                        | **Electric** | Dark purple -> Blue -> Cyan -> White |

                                                        ---

                                                        ## Getting Started

                                                        ### Prerequisites

                                                        - GCC compiler
                                                        - GNU Make
                                                        - MiniLibX (included or system-installed)
                                                        - X11 development libraries (Linux)

                                                        ```bash
                                                        # Linux -- install X11 dependencies
                                                        sudo apt-get install libx11-dev libxext-dev libbsd-dev

                                                        # macOS -- MiniLibX uses AppKit (no extra deps)
                                                        ```

                                                        ### Compilation

                                                        ```bash
                                                        make          # Build fract-ol
                                                        make clean    # Remove object files
                                                        make fclean   # Full clean
                                                        make re       # Rebuild
                                                        ```

                                                        ---

                                                        ## Usage Examples

                                                        ```bash
                                                        # Mandelbrot set
                                                        ./fractol mandelbrot

                                                        # Julia set with default parameters
                                                        ./fractol julia

                                                        # Julia set with custom c parameter
                                                        ./fractol julia -0.745 0.186

                                                        # Burning Ship fractal
                                                        ./fractol burning_ship
                                                        ```

                                                        ---

                                                        ## Technical Details

                                                        | Aspect | Implementation |
                                                        |:-------|:--------------|
                                                        | **Graphics** | MiniLibX -- direct pixel buffer manipulation |
                                                        | **Rendering** | Per-pixel complex number iteration |
                                                        | **Color** | HSV-to-RGB conversion for smooth gradients |
                                                        | **Zoom** | Mouse-centered coordinate remapping |
                                                        | **Precision** | `double` precision floating point |
                                                        | **Max Iter** | Dynamic -- adjustable at runtime |

                                                        ---

                                                        ## Author

                                                        **Adil Bourji** -- [@adi7-x](https://github.com/adi7-x)

                                                        <p align="center">
                                                          <a href="https://github.com/adi7-x"><img src="https://img.shields.io/badge/GitHub-adi7--x-181717?style=flat-square&logo=github" /></a>
                                                            <a href="https://linkedin.com/in/adil-bourji"><img src="https://img.shields.io/badge/LinkedIn-Adil_Bourji-0A66C2?style=flat-square&logo=linkedin" /></a>
                                                            </p>

                                                            <p align="center"><sub>42 School . Common Core . Computer Graphics</sub></p>
                                                            
