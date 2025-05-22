import subprocess
import sys

# 需要安装的工具列表 (请根据实际需求修改)
TOOLS_TO_INSTALL = [
    "fastapi",
    "uvicorn",
    "pydantic",
    # 在这里添加其他MCP服务所需的依赖包
]

def check_uv_installed():
    """检查系统中是否安装了uv"""
    try:
        subprocess.run(["uv", "--version"], check=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        print("检测到 uv 已安装。")
        return True
    except FileNotFoundError:
        print("错误：未检测到 uv。请先安装 uv。")
        print("您可以访问 https://github.com/astral-sh/uv 获取安装指南。")
        return False
    except subprocess.CalledProcessError:
        print("错误：uv 命令执行失败，请检查 uv 是否正确安装并配置在PATH中。")
        return False

def install_tool(tool_name):
    """使用uv安装指定的工具"""
    try:
        print(f"正在尝试使用 uv 安装 {tool_name}...")
        # 注意：uv 使用 'uv pip install' 命令来安装包
        process = subprocess.run(["uv", "pip", "install", tool_name], check=True, capture_output=True, text=True)
        print(f"成功安装 {tool_name}。")
        if process.stdout:
            print(f"输出:\n{process.stdout}")
        return True
    except subprocess.CalledProcessError as e:
        print(f"安装 {tool_name} 失败。")
        print(f"错误信息: {e.stderr}")
        return False
    except FileNotFoundError:
        # 这个异常理论上在 check_uv_installed 中已经处理，但作为双重保险
        print("错误：未找到 uv 命令。请确保 uv 已安装并添加到系统PATH中。")
        return False

def main():
    print("开始为Trae智能体MCP服务安装所需工具...")

    if not check_uv_installed():
        sys.exit(1)

    successful_installs = []
    failed_installs = []

    for tool in TOOLS_TO_INSTALL:
        if install_tool(tool):
            successful_installs.append(tool)
        else:
            failed_installs.append(tool)

    print("\n安装总结:")
    if successful_installs:
        print(f"成功安装的工具: {', '.join(successful_installs)}")
    if failed_installs:
        print(f"安装失败的工具: {', '.join(failed_installs)}")
        print("请检查上述错误信息并尝试手动安装失败的工具。")
    else:
        print("所有工具均已成功安装！")

if __name__ == "__main__":
    main()