# leia a página: 27, 30, 35
# NOTE E ADOTE: leia o enunciado

import numpy as np
import matplotlib.pyplot as plt

def phase(x): # em graus
    return ((180/np.pi)*(np.arctan2(x.imag,x.real)))

def modulo(x):
    return np.sqrt(x.real*x.real + x.imag*x.imag)
            
def polar(x):
    print(str(modulo(x)) + "/_" + str(phase(x)))
    
def cart2pol(x, y):
    rho = np.sqrt(x**2 + y**2)
    phi = 180*np.arctan2(y, x)/np.pi
    return(rho, phi)

def pol2cart(rho, phi):
    x = rho * np.cos(phi)
    y = rho * np.sin(phi)
    return x + y*1j
def em_rad(graus):
    return graus*np.pi/180

alpha = pol2cart(1,em_rad(120))

vg = 13800
comp12 = 10
comp23 = 23
zp =  0.2779 + 0.3921j
zeq1 = 1.15j
vFase = vg/pol2cart((np.sqrt(3)), 30*np.pi/180)
Eq1_a = vFase
Eq1_b = vFase*alpha**2
Eq1_c = vFase*alpha

# Impedâncias abaixo:

zc1_a = 83.91 + 33.01j
zc1_b = 117.47 + 46.21j
zc1_c = 73.42 + 28.89j

zc2_a = 617.56 + 231.35j
zc2_b = 540.36 + 202.43j
zc2_c = 385.97 + 144.59j

zc3_a = 165.26 + 60.83j
zc3_b = 198.32 + 73.00j
zc3_c = 123.95 + 45.62j
zn3 = 5.6 + 2.06j

# Admitâncias abaixo:

yc1_a = 1/zc1_a
yc1_b = 1/zc1_b
yc1_c = 1/zc1_c

yc2_a = 1/zc2_a
yc2_b = 1/zc2_b
yc2_c = 1/zc2_c

yc3_a = 1/zc3_a
yc3_b = 1/zc3_b
yc3_c = 1/zc3_c

yeq1 = 1/zeq1

def poe_na_matriz(yeq,ya,yb,yc):
    # matriz = np.diag(np.array([yeq + yc_a, yeq + yc_b, yeq + yc_c, yc_a + yc_b + yc_c]))
    # matriz[3] = np.array([-yc_a, -yc_b, -yc_c, yc_a+yc_b+yc_c])
    # matriz[:][3] = np.array([-yc_a, -yc_b, -yc_c, yc_a+yc_b+yc_c])
    matriz = np.array([[yeq+ya, 0     , 0       , -ya],
                       [0     , yeq+yb, 0       , -yb],
                       [0     , 0     , yeq+yc  , -yc],
                       [-ya   , -yb   , -yc     , ya+yb+yc]])
    
    return matriz

Y = poe_na_matriz(yeq1, yc1_a, yc1_b, yc1_c)

def calcula_tensoes(Y,Ea,Eb,Ec,Yeq):
    I = np.array([[Yeq*Ea],[Yeq*Eb],[Yeq*Ec],[0]])
    print(I.shape)
    V = np.dot(np.linalg.inv(Y), I)
    return V

# Item A
tensoesdoitema = calcula_tensoes(poe_na_matriz(yeq1, yc1_a, yc1_b, yc1_c),Eq1_a, Eq1_b, Eq1_c, yeq1)
