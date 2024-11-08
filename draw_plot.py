import pandas as pd
import matplotlib.pyplot as plt

# CSV 파일 경로 설정
file1_path = '/home/jang/2024_7Dof/cul_pos.csv'
file2_path = '/home/jang/2024_7Dof/real_pos.csv'

# CSV 파일 읽기
def parse_csv(file_path):
    data = {'x': [], 'y': [], 'z': []}
    with open(file_path, 'r') as file:
        for line in file:
            parts = line.strip().split(', ')
            x_val = float(parts[0].split(': ')[1])
            y_val = float(parts[1].split(': ')[1])
            z_val = float(parts[2].split(': ')[1])
            data['x'].append(x_val)
            data['y'].append(y_val)
            data['z'].append(z_val)
    return pd.DataFrame(data)

# 각 파일에 대해 DataFrame 생성
df1 = parse_csv(file1_path)
df2 = parse_csv(file2_path)

# 그래프 그리기
plt.figure(figsize=(12, 8))

# X 값 플롯
plt.subplot(3, 1, 1)
plt.plot(df1.index, df1['x'], label='cul_pos X', color='blue')
plt.plot(df2.index, df2['x'], label='real_pos X', color='orange')
plt.xlabel('Index')
plt.ylabel('X Value')
plt.title('X Values Comparison')
plt.legend()

# Y 값 플롯
plt.subplot(3, 1, 2)
plt.plot(df1.index, df1['y'], label='cul_pos Y', color='blue')
plt.plot(df2.index, df2['y'], label='Freal_pos Y', color='orange')
plt.xlabel('Index')
plt.ylabel('Y Value')
plt.title('Y Values Comparison')
plt.legend()

# Z 값 플롯
plt.subplot(3, 1, 3)
plt.plot(df1.index, df1['z'], label='cul_pos Z', color='blue')
plt.plot(df2.index, df2['z'], label='real_pos Z', color='orange')
plt.xlabel('Index')
plt.ylabel('Z Value')
plt.title('Z Values Comparison')
plt.legend()

# 그래프 출력
plt.tight_layout()
plt.show()
