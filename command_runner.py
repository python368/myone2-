import subprocess
import sys

def run_command(cmd):
    """执行命令并返回(退出码, 输出)元组"""
    try:
        # 安全执行命令
        result = subprocess.run(
            cmd,
            shell=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            encoding='utf-8',
            errors='replace',
            check=False
        )
        return result.returncode, result.stdout
    except Exception as e:
        return -1, f"命令执行错误: {str(e)}"

# 优化示例用法
if __name__ == "__main__":
    # 测试命令
    commands = [
        "ls -la",          # 成功命令
        "non_existent_cmd" # 失败命令
    ]
    
    for cmd in commands:
        print(f"执行命令: {cmd}")
        exit_code, output = run_command(cmd)
        print(f"退出码: {exit_code}")
        print("输出内容:")
        print("-" * 50)
        print(output)
        print("=" * 50 + "\n")
