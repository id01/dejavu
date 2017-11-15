## DejaVU
A program that creates fake files to replace the real ones in a hard drive.  
This makes it harder for hackers trying to steal data off a hard drive with forensic tools to find reminants of valid files.  

## Compilation
```
gcc -O3 dejavu.c -o dejavu
```

## Usage (testing)
```
./dejavu > /tmp/testfile
```

## Usage (erasing disk)
```
./dejavu | dd of=/dev/sda1
```
