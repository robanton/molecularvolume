import numpy
from distutils.core import setup, Extension
from Cython.Build import cythonize
import os

floodfilldir = os.path.abspath(os.getcwd())
print(floodfilldir)

ext_modules=[
    Extension("volume",
        sources=["volume.pyx"],
        libraries=["m", "fllodfill3d"],
        library_dirs=[floodfilldir],
        extra_compile_args=["-O3"]
    )
]


setup(
    name="volume",
    ext_modules=cythonize(ext_modules),
    include_dirs=[numpy.get_include()],
    library_dirs=[floodfilldir]
)
