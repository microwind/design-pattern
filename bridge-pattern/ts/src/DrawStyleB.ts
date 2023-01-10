import { DrawTool } from './DrawTool.js'

// 画圆B，实现了图画基础API
export class DrawStyleB implements DrawTool {
  drawStyle() {
    console.log('DrawStyeB:drawStyle()')
  }
}
