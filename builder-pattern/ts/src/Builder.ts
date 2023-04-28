export interface Builder {
  reset(): void
  setName(name: string): Builder
  setScreen(size: number[]): Builder
  setGPU(no: number): Builder
}
