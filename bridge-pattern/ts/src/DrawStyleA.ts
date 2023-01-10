import { DrawTool } from './DrawTool.js'

// 画圆A，实现了图画基础API
export class DrawStyleA implements DrawTool {
  drawStyle() {
    console.log('DrawStyleA:drawStyle()')
  }
}
