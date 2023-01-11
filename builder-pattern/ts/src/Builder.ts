export interface Builder {
  reset(): void
  setName(name: string): void
  setScreen(size: number[]): void
  setGPU(no: number): void
}
