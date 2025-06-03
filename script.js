// 折叠面板功能
document.querySelectorAll('.toggle').forEach(button => {
    button.addEventListener('click', () => {
        const section = button.closest('section');
        const content = section.querySelector('.content');
        content.style.display = content.style.display === 'none' ? 'block' : 'none';
        button.textContent = content.style.display === 'none' ? '展开' : '收起';
    });
});

// 费用计算器
document.getElementById('calculate').addEventListener('click', () => {
    const visitors = parseInt(document.getElementById('visitors').value) || 1;
    const cableway = parseInt(document.getElementById('cableway').value) || 0;
    
    // 基础费用（门票+素斋）
    const baseCost = 55 + 30;
    const total = visitors * (baseCost + cableway);
    
    document.getElementById('result').textContent = `总费用：¥${total}`;
});

// 模拟地图缩放
let scale = 1;
document.getElementById('zoomIn').addEventListener('click', () => {
    scale *= 1.2;
    document.getElementById('map').style.transform = `scale(${scale})`;
});

document.getElementById('zoomOut').addEventListener('click', () => {
    scale /= 1.2;
    document.getElementById('map').style.transform = `scale(${scale})`;
});

// 模拟天气数据
function updateWeather() {
    const weatherData = [
        { condition: "☀️ 晴朗", temp: "18-24℃", wind: "微风" },
        { condition: "🌤️ 多云", temp: "16-22℃", wind: "2级" },
        { condition: "🌧️ 小雨", temp: "15-20℃", wind: "3级" }
    ];
    
    const weather = weatherData[Math.floor(Math.random() * weatherData.length)];
    document.querySelector('#weather p').innerHTML = `
        <span style="font-size: 2rem">${weather.condition}</span><br>
        <strong>温度:</strong> ${weather.temp}<br>
        <strong>风力:</strong> ${weather.wind}
    `;
}

// 初始化页面
window.addEventListener('DOMContentLoaded', () => {
    // 默认收起所有内容区域
    document.querySelectorAll('.content').forEach(content => {
        content.style.display = 'none';
    });
    
    // 更新天气
    updateWeather();
    
    // 每30分钟更新一次天气
    setInterval(updateWeather, 1800000);
    
    // 初始计算费用
    document.getElementById('calculate').click();
});

// 时间轴动画
let timelineItems = document.querySelectorAll('.timeline-item');
timelineItems.forEach((item, index) => {
    setTimeout(() => {
        item.style.opacity = '1';
        item.style.transform = 'translateY(0)';
    }, 300 * index);
});
