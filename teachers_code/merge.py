import os

# 目标目录
directory = '.'

# 输出文件名
output_file = 'merged.txt'

# 打开输出文件
with open(output_file, 'w', encoding='utf-8') as outfile:
    # 遍历目录中的所有文件
    for filename in os.listdir(directory):
        # 只处理txt文件
        if filename.endswith('.txt'):
            # 写入文件名
            outfile.write(f'## {filename}\n```c\n')
            # 打开并读取文件内容
            with open(os.path.join(directory, filename), 'r', encoding='utf-8') as infile:
                try:
                    # 读取文件内容
                    content = infile.read()
                    # 写入文件内容
                    outfile.write(content)
                    outfile.write('\n```\n\n')  # 添加换行以分隔不同文件的内容
                except UnicodeDecodeError as e:
                    continue
                

print(f'所有txt文件已合并到 {output_file}')