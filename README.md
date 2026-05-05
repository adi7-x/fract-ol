# Fract-ol

[Score: 125/100](https://img.shields.io/badge/Score-125%2F100-brightgreen?style=for-the-badge)
[Language: C](https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
[School: 42 Network](https://img.shields.io/badge/42_Network-000000?style=for-the-badge&logo=42&logoColor=white)
[Library: MiniLibX](https://img.shields.io/badge/MiniLibX-Graphics-orange?style=for-the-badge)

*The beauty of mathematics rendered pixel by pixel.*

A real-time fractal exploration engine built with MiniLibX. Renders Mandelbrot, Julia, and Burning Ship sets with smooth coloring, infinite zoom, and interactive navigation.

---

## Table of Contents

* [About](#about)
* * [Supported Fractals](#supported-fractals)
  * * [The Mathematics](#the-mathematics)
    * * [Controls](#controls)
      * * [Color Schemes](#color-schemes)
        * * [Getting Started](#getting-started)
          * * [Usage Examples](#usage-examples)
            * * [Technical Details](#technical-details)
              * * [Screenshots](#screenshots)
                * * [Author](#author)
                 
                  * ---
                 
                  * ## About
                 
                  * **Fract-ol** is a graphical project at 42 School that challenges students to create a fractal visualization tool. It focuses on the MiniLibX library, complex number mathematics, and optimization for real-time rendering.
                 
                  * ---
                 
                  * ## Supported Fractals
                 
                  * 1. **Mandelbrot Set:** The classic fractal defined by the sequence z(n+1) = z(n)^2 + c.
                    2. 2. **Julia Set:** Customizable fractal by passing initial parameters.
                       3. 3. **Burning Ship:** A variation that produces a ship-like structure.
                         
                          4. ---
                         
                          5. ## The Mathematics
                         
                          6. The core of the project is the iteration of the complex function:
                          7. `f(z) = z^2 + c`
                         
                          8. Where:
                          9. * **z** starts at 0 (for Mandelbrot) or the pixel coordinate (for Julia).
                             * * **c** is the pixel coordinate (for Mandelbrot) or a constant parameter (for Julia).
                               * * The pixel color is determined by how quickly the sequence diverges.
                                
                                 * ---
                                
                                 * ## Controls
                                
                                 * * **Mouse Wheel:** Zoom in and out at the cursor position.
                                   * * **Arrow Keys:** Pan across the fractal.
                                     * * **C Key:** Cycle through different color palettes.
                                       * * **R Key:** Reset zoom and position to default.
                                         * * **ESC:** Exit the application.
                                          
                                           * ---
                                          
                                           * ## Color Schemes
                                          
                                           * The project implements several smooth coloring algorithms to avoid the "banded" look of basic iteration counting:
                                           * * **Psychedelic:** Rapidly changing colors based on iteration.
                                             * * **Monochrome:** Shades of a single color for a clean look.
                                               * * **RGB Shift:** Dynamic shifting of color channels.
                                                
                                                 * ---
                                                
                                                 * ## Getting Started
                                                
                                                 * ### Prerequisites
                                                
                                                 * * GCC compiler
                                                   * * MiniLibX library
                                                     * * X11 development headers
                                                      
                                                       * ### Compilation
                                                      
                                                       * ```bash
                                                         make
                                                         ```

                                                         ---

                                                         ## Usage Examples

                                                         ```bash
                                                         # Render Mandelbrot
                                                         ./fractol mandelbrot

                                                         # Render Julia with custom parameters
                                                         ./fractol julia 0.285 0.01

                                                         # Render Burning Ship
                                                         ./fractol ship
                                                         ```

                                                         ---

                                                         ## Technical Details

                                                         * **Language:** C
                                                         * * **Graphics:** MiniLibX
                                                           * * **Optimization:** Mathematical shortcuts to detect divergence early.
                                                             * * **Events:** Efficient handling of mouse and keyboard hooks.
                                                              
                                                               * ---
                                                              
                                                               * ## Screenshots
                                                              
                                                               * *(Add your screenshots here to showcase your work!)*
                                                              
                                                               * ---
                                                              
                                                               * ## Author
                                                              
                                                               * **Adil Bourji** -- [@adi7-x](https://github.com/adi7-x)
                                                              
                                                               * [GitHub](https://img.shields.io/badge/GitHub-adi7--x-181717?style=flat-square&logo=github)
                                                               * [LinkedIn](https://img.shields.io/badge/LinkedIn-Adil_Bourji-0A66C2?style=flat-square&logo=linkedin)
                                                              
                                                               * *42 School . Common Core . Graphics*
                                                               * 
