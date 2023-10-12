# Pi parallel calculation

The number pi is calculated by Monte Carlo method.
## How Monte Carlo method work
The concept involves simulating random points (x, y) on a 2-D plane within a square domain of side length 2r, centered at the coordinates (0,0). Envision a circle with a radius of r positioned within the same domain, inscribed perfectly within the square. Next, we determine the ratio of points that fall inside the circle to the total number of points generated. Please refer to the accompanying image for a visual representation:

<img src="https://github.com/DimaKrasav4eg/pi-par-calculation/blob/master/images/graph.png" width="400">

We know that $$\frac{S_circle}{S_square}=\frac{{\pi}r^2}{(2r)^2}=\frac{\pi}{4}$$
Then we get $$\pi=4\frac{points-inside-circle}{total-points}$$

## How to start
```sh
./start.sh
```
`--draw` - create and show graph
`--points` - set number of points