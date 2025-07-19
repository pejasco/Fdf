<h1 align="center">FDF - Wireframe 3D Viewer</h1>
<p align="center">A 3D wireframe visualization program that transforms 2D heightmaps into beautiful 3D projections using isometric and orthographic rendering.</p>

<h2 align="center">🎥 Demo</h2>
<p align="center">
  <img src="./gif/demo/42_color.gif" width="45%" alt="42 Color Demo" />
  <img src="./gif/demo/42_org.gif" width="45%" alt="42 Org Demo" /><br />
  <img src="./gif/demo/complex.gif" width="45%" alt="Complex Demo" />
  <img src="./gif/demo/inverted.gif" width="45%" alt="Inverted Demo" />
</p>

<hr/>

<h2>📌 Table of Contents</h2>
<ul>
  <li><a href="#about">About</a></li>
  <li><a href="#features">Features</a></li>
  <li><a href="#installation">Installation</a></li>
  <li><a href="#usage">Usage</a></li>
  <li><a href="#controls">Controls</a></li>
  <li><a href="#map-format">Map Format</a></li>
  <li><a href="#project-structure">Project Structure</a></li>
  <li><a href="#git-setup">Git Setup</a></li>
  <li><a href="#contributing">Contributing</a></li>
  <li><a href="#license">License</a></li>
</ul>

<hr/>

<h2 id="about">📖 About</h2>
<p>
FDF (<em>Fil de Fer</em>, French for "wireframe") is a graphics project that creates 3D wireframe representations of 2D heightmaps.
The program reads map files containing elevation data and renders them as interactive 3D visualizations using the MinilibX graphics library.
</p>
<p>This project demonstrates:</p>
<ul>
  <li>3D mathematics and transformations</li>
  <li>Isometric and orthographic projections</li>
  <li>Line drawing algorithms (Bresenham's)</li>
  <li>Color interpolation and gradients</li>
  <li>Event handling and user interaction</li>
</ul>

<h2 id="features">✨ Features</h2>
<ul>
  <li><strong>Multiple Projection Modes</strong>: Isometric and orthographic views</li>
  <li><strong>Interactive Controls</strong>: Rotate, scale, translate wireframes in real time</li>
  <li><strong>Color Support</strong>: Heightmaps with smooth color gradients</li>
  <li><strong>Smooth Rendering</strong>: Optimized lines and anti-aliasing</li>
  <li><strong>Dynamic Transformations</strong>: Real-time model manipulation</li>
  <li><strong>Multiple Map Support</strong>: Compatible with various heightmap formats</li>
</ul>

<h2 id="installation">⚙️ Installation</h2>

<h3>Quick Setup</h3>
<p>Use the provided installation script to automatically install all dependencies:</p>

<pre><code class="bash">./config.sh
</code></pre>

<p>This script will:</p>
<ul>
  <li>Update your system packages</li>
  <li>Install build tools (GCC, Make)</li>
  <li>Install X11 development libraries</li>
  <li>Clone and set up the MinilibX library</li>
</ul>

<h3>Manual Compilation</h3>
<pre><code>
# Compile the project
make

# Compile with bonus features
make bonus

# Clean build files
make clean

# Remove all generated files
make fclean

# Rebuild everything
make re
</code></pre>

<h2 id="controls">🎮 Controls</h2>

<h3>🧠 Keyboard Controls</h3>
<ul>
  <li><strong>ESC</strong>: Exit program <br/><img src="./gif/control/exit.gif" width="300" alt="Exit program demonstration" /></li>
  <li><strong>Arrow Keys</strong>: Move/translate the wireframe <br/><img src="./gif/control/move.gif" width="300" alt="Wireframe movement demonstration" /></li>
  <li><strong>I </strong>: Zoom in <br/><img src="./gif/control/in.gif" width="300" alt="Zoom in demonstration" /></li>
  <li><strong>O </strong>: Zoom out <br/><img src="./gif/control/out.gif" width="300" alt="Zoom out demonstration" /></li>
  <li><strong>Q / E</strong>: Rotate Y-axis <br/><img src="./gif/control/y.gif" width="300" alt="Rotate Y-axis demonstration" /></li>
  <li><strong>W / S</strong>: Rotate X-axis <br/><img src="./gif/control/x.gif" width="300" alt="Rotate X-axis demonstration" /></li>
  <li><strong>A / D</strong>: Rotate Z-axis <br/><img src="./gif/control/z.gif" width="300" alt="Rotate Z-axis demonstration" /></li>
</ul>

<h3>🖱️ Mouse Controls</h3>
<ul>
  <li><strong>Scroll Up</strong>: Zoom in <br/><img src="./gif/control/m_in.gif" width="300" alt="Mouse zoom in demonstration" /></li>
  <li><strong>Scroll Down</strong>: Zoom out <br/><img src="./gif/control/m_out.gif" width="300" alt="Mouse zoom out demonstration" /></li>
</ul>

<h2 id="map-format">🗺️ Map Format</h2>
<p>FDF accepts heightmap files like this:</p>

<pre><code>0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
0 0 10 10 0 0 10 10 0 0 0 10 10 10 10 10 0 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 0 0 10 10 0 0 0 0 0 0 0 10 10 0 0
0 0 10 10 10 10 10 10 0 0 0 0 10 10 10 10 0 0 0
0 0 0 10 10 10 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 0 0 0 0 0 0
0 0 0 0 0 0 10 10 0 0 0 10 10 10 10 10 10 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
</code></pre>

<p><strong>With Colors:</strong> You can add hexadecimal color codes like this:</p>

<pre><code>0 0 0,0xFFFFFF 0 0
0 0 10,0xFF0000 10 0 0
0 0 10 10 0 0
</code></pre>

<p><strong>Made by CF Leung</strong></p>
<p><em>Last updated: July 2025</em></p>