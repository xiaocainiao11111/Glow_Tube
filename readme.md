# 1、项目介绍
一套简易的sz-8辉光管驱动电路，兼容qs30-1型号，采用成品180V升压模块和驱动ic，主控为esp32，难度不大。

<img src=https://github.com/xiaocainiao11111/Glow_Tube/blob/main/images/d279668a0749e85de30a161ba6a3003.jpg width=40% />

# 2、文件夹介绍
software：esp32源码

hardware：bom表，原理图，实物图

images：readme图片
# 3、真爱党复刻说明
 ### 1、高压危险！！高压危险！！一定要检查接线，20k电阻一定要接，单片机的gnd可以与辉光管部分隔离（击穿了至少保住mcu。。）
2、hardware/bom里180v升压模块和驱动ic的链接详情一定要看一下，看完就会接线和写代码了，发现自己的管有个别数字显示不出就修改对应数字的高低电平。

<img src=https://github.com/xiaocainiao11111/Glow_Tube/blob/main/images/147f684ba0818192675865005e36abf.png width=40% />

3、代码平台为vscode_platformio插件，想用arduino的把main.cpp的内容直接复制粘贴过去就行，不用修改。

# 4、后话
<img src=https://github.com/xiaocainiao11111/Glow_Tube/blob/main/images/tube.png width=35% />
El Psy Congroo 

相信很多入坑辉光管的都是石头门过来的，希望我们在最完美的那条世界线。可惜只有一个辉光管，还是小型的，现在的辉光管涨价严重,十几年前几毛钱，现在基本35往上了，动画原版IN-12型都上百的，反正我这一套大概100块左右，可以说性价比极低了，非电子管发烧友看个乐就行，确实感兴趣可以多蹲蹲海鲜市场之类的，相信diyer总有自己的方法。

# *make by xiaocainiao* 

