# colorflow-to-feyman: Convert from color flows to Feynman diagram in QCD
![alt text](https://github.com/martinfoell/colorflow-to-feynman/blob/main/images/image.png)|

# Description

In Quantum Chromo Dynamics (QCD) in particle physics the color charges for the quark/anti-quarks and gluons can be put together in what is called *color flows* as shown to the left in the picture above. The purpose of this program is to convert these color flows to a Feynman diagram as shown to to right in the picture above. The details of the method used to convert between the color flows and the Feynman diagram can be found in chapter 6 [here](https://www.duo.uio.no/handle/10852/104703).

# Setup

Here is a short guide for how to set up the program and run it with the color flows in the example in example.txt.
## install
```bash
https://github.com/martinfoell/colorflow-to-feynman.git
```
## build (in the same folder as Makefile)
```bash
make
```

## run
```bash
cd bin
./main
```

# Example
The input format for the color flows to the program are stored in a .txt file. The input example.txt is given below and corresponds to the example in the picture above.
```
in = q1, Q2
inter = g
out = q3, Q4
cf1 = q1, g, Q2
cf2 = Q4, g, q3
```

| Input variable |     Description       |  Value  | Figure 1 |
|----------------|-----------------------|---------|----------|
| in		 |incomming particles    |  q1, Q2 | $q_1$, $\overline{q}_2|
| inter		 |intermediate particles |  g      ||
| out		 |outgiong particles     |    q3, Q4  |	|
| cf1		 |     color flow 1      |  q1, g, Q2 ||
| cf2		 |     color flow 2      |  Q4, g, q3 |	|

