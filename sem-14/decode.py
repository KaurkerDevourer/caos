import zlib
filename = '/home/styopkin/test/.git/objects/32/79f6ee8b01866544708c0178ebd435963bd5a0'
compressed_contents = open(filename, 'rb').read()
decompressed_contents = zlib.decompress(compressed_contents)
print(decompressed_contents)
