import os
files = os.listdir('database/train')
print("总文件数:", len(files))
print("前 10 个文件名:", files[:10])