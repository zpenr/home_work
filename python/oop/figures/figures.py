import math

class Shape3D:
    def __init__(self):
        pass
    def get_volume(self):
        pass
    def get_surface_area(self):
        pass

class Cube(Shape3D):
    def __init__(self, a):
        self.a = a
    def get_volume(self):
        return self.a ** 3
    def get_surface_area(self):
        return 6 * (self.a ** 2)

class Sphere(Shape3D):
    def __init__(self, r):
        self.r = r
    def get_volume(self):
        return (4/3) * math.pi * (self.r ** 3)
    def get_surface_area(self):
        return 4 * math.pi * (self.r ** 2)

class Cylinder(Shape3D):
    def __init__(self, r, h):
        self.r = r
        self.h = h
    def get_volume(self):
        return math.pi * (self.r ** 2) * self.h
    def get_surface_area(self):
        return 2 * math.pi * self.r * (self.h + self.r)

class Parallelepiped(Shape3D):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    def get_volume(self):
        return self.a * self.b * self.c
    def get_surface_area(self):
        return 2 * (self.a*self.b + self.b*self.c + self.a*self.c)

class Ellipsoid(Shape3D):
    def __init__(self, a, b, c):
        self.a = a
        self.b = b
        self.c = c
    def get_volume(self):
        return (4/3) * math.pi * self.a * self.b * self.c
    def get_surface_area(self):
        p = 1.6075
        part = ((self.a*self.b)**p + (self.a*self.c)**p + (self.b*self.c)**p) / 3
        return 4 * math.pi * (part ** (1/p))


def find_dominant_shapes(shapes_list):
    total_volume = sum(shape.get_volume() for shape in shapes_list)
    
    for shape in shapes_list:
        vol = shape.get_volume()
        others_vol = total_volume - vol
        
        if vol >= others_vol:
            return True
            
    return False


shapes = [
    Cube(2),
    Sphere(1),
    Parallelepiped(10, 10, 10)
]

print(find_dominant_shapes(shapes))