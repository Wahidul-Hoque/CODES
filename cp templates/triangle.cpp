#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define ll long long
#define ld long double

ld Gx, Gy; // Centroid
ld Ox, Oy; // Circumcenter
ld Ix, Iy; // Incenter
ld Hx, Hy; // Orthocenter

/* 1. Centroid (G)
   The point where the three medians intersect.
*/
void get_centroid(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy, ld &Gx, ld &Gy) {
    Gx = (Ax + Bx + Cx) / 3.0L;
    Gy = (Ay + By + Cy) / 3.0L;
}

/* 2. Circumcenter (O)
   The center of the circle that passes through all three vertices.
*/
void get_circumcenter(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy, ld &Ox, ld &Oy) {
    ld D = 2.0L * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By));
    ld A2 = Ax * Ax + Ay * Ay;
    ld B2 = Bx * Bx + By * By;
    ld C2 = Cx * Cx + Cy * Cy;
    Ox = (A2 * (By - Cy) + B2 * (Cy - Ay) + C2 * (Ay - By)) / D;
    Oy = (A2 * (Cx - Bx) + B2 * (Ax - Cx) + C2 * (Bx - Ax)) / D;
}

/* 3. Incenter (I)
   The center of the inscribed circle that is tangent to each side.
*/
void get_incenter(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy, ld &Ix, ld &Iy) {
    ld a = sqrtl((Bx - Cx) * (Bx - Cx) + (By - Cy) * (By - Cy));
    ld b = sqrtl((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy));
    ld c = sqrtl((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
    ld p = a + b + c;
    Ix = (a * Ax + b * Bx + c * Cx) / p;
    Iy = (a * Ay + b * By + c * Cy) / p;
}

/* 3. Orthocenter (H)
   The intersection of the three altitudes.
   Calculated using the Euler Line property: H = 3G - 2O.
*/
void get_orthocenter(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy, ld &Hx, ld &Hy) {
    ld Gx, Gy, Ox, Oy;
    
    // Reuse your Centroid function
    get_centroid(Ax, Ay, Bx, By, Cx, Cy, Gx, Gy);

    // Reuse your Circumcenter function
    get_circumcenter(Ax, Ay, Bx, By, Cx, Cy, Ox, Oy);

    // H = 3G - 2O
    Hx = 3.0L * Gx - 2.0L * Ox;
    Hy = 3.0L * Gy - 2.0L * Oy;
}


const ld PI = acosl(-1.0L);

// 1. Area of Triangle
ld get_area(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy) {
    ld res = 0.5L * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By));
    return (res < 0 ? -res : res); 
}

/* 2. Angle at a Center Point (B)
   Calculates the angle ABC in degrees using the dot product formula.
   Includes a clamping mechanism to prevent NaN errors from precision loss.
*/
ld get_angle(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy) {
    ld v1x = Ax - Bx, v1y = Ay - By;
    ld v2x = Cx - Bx, v2y = Cy - By;
    ld dot = v1x * v2x + v1y * v2y;
    ld mag1 = sqrtl(v1x * v1x + v1y * v1y);
    ld mag2 = sqrtl(v2x * v2x + v2y * v2y);
    // Clamp value to [-1, 1] to avoid NaN in acosl due to precision
    ld cos_theta = dot / (mag1 * mag2);
    if (cos_theta > 1.0L) cos_theta = 1.0L;
    if (cos_theta < -1.0L) cos_theta = -1.0L;
    return acosl(cos_theta) * 180.0L / PI;
}

// set precision for floating-point output
// ld num = 123.456789123;
// // This is the "Golden Line" for CP output
// cout << fixed << setprecision(6) << num << '\n';

// Returns: 0 if collinear, 1 if clockwise, 2 if counter-clockwise
int orientation(ld Ax, ld Ay, ld Bx, ld By, ld Cx, ld Cy) {
    ld val = (By - Ay) * (Cx - Bx) - (Bx - Ax) * (Cy - By);
    if (abs(val) < 1e-12) return 0;  // Collinear
    return (val > 0) ? 1 : 2;       // CW or CCW
}
