import asyncio
import websockets
import json
from typing import Dict, Any

class MCPClient:
    def __init__(self, url: str = "ws://localhost:8765"):
        self.url = url
        
    async def register_tool(self, name: str, tool_definition: Dict[str, Any]):
        """注册一个新工具到MCP服务器"""
        async with websockets.connect(self.url) as ws:
            message = {
                "type": "tool_registration",
                "name": name,
                "definition": tool_definition
            }
            await ws.send(json.dumps(message))
            response = await ws.recv()
            return json.loads(response)
            
    async def invoke_tool(self, name: str, parameters: Dict[str, Any]):
        """调用一个已注册的工具"""
        async with websockets.connect(self.url) as ws:
            message = {
                "type": "tool_invocation",
                "name": name,
                "parameters": parameters
            }
            await ws.send(json.dumps(message))
            response = await ws.recv()
            return json.loads(response)
            
    async def update_context(self, context: Dict[str, Any]):
        """更新服务器上的上下文信息"""
        async with websockets.connect(self.url) as ws:
            message = {
                "type": "context_update",
                "context": context
            }
            await ws.send(json.dumps(message))
            response = await ws.recv()
            return json.loads(response)

async def main():
    client = MCPClient()
    
    # 示例：注册一个新工具
    tool_def = {
        "name": "image_generator",
        "description": "生成图像的工具",
        "parameters": {
            "prompt": "str",
            "size": "tuple[int, int]"
        }
    }
    
    response = await client.register_tool("image_generator", tool_def)
    print("工具注册响应:", response)
    
    # 示例：调用工具
    result = await client.invoke_tool("image_generator", {
        "prompt": "一只可爱的猫",
        "size": [512, 512]
    })
    print("工具调用结果:", result)

if __name__ == "__main__":
    asyncio.run(main())
