from setuptools import setup, find_packages


URL = 'https://github.com/cospectrum/fft/tree/main/Python'

with open('README.md', 'r') as f:
    long_description = f.read()


setup(
    name='fft',
    version='0.1.0',
    license='MIT',
    url=URL,
    description='Fast Fourier Transform',
    long_description=long_description,
    long_description_content_type='text/markdown',
    author='Alexey Severin',
    install_requires=[],
    packages=find_packages(),
    keywords=['pubmed', 'scraper'],
)
