Almost, but **not yet**. The new guess (z_1) is not what you plot. You keep going until it settles.

The process is:

### 1. Pick a starting guess

Example:

[
z_0 = 2
]

You are saying:

> "I think the root might be near 2."

---

### 2. Apply Newton's formula

[
z_1=z_0-\frac{f(z_0)}{f'(z_0)}
]

For:

[
f(z)=z^3-1
]

and:

[
f'(z)=3z^2
]

you get:

[
z_1=2-\frac{2^3-1}{3(2^2)}
]

[
z_1=1.4167
]

Now your guess improved.

---

### 3. Repeat

Use the new guess:

[
z_2=1.4167-\frac{f(1.4167)}{f'(1.4167)}
]

You get closer:

[
z_2\approx1.110
]

Again:

[
z_3\approx1.013
]

Eventually:

[
z_n\approx1
]

Now you say:

> "This starting point belongs to the root 1."

**Then you plot/color the original starting point (z_0)**, not the final answer.

---

For a fractal:

Imagine one pixel:

```
pixel coordinate:
z0 = -0.3 + 0.7i
```

Run Newton:

```
z0
 ↓
z1
 ↓
z2
 ↓
z3
 ↓
root
```

Maybe it ends at:

```
root A
```

So you color the pixel:

```
-0.3 + 0.7i = color A
```

The final root is just information.

The picture is a map of:

> "Where did every starting guess go?"

That is what creates the Newton fractal.
