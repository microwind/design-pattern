class Context:
  strategy_a = None
  def __init__(self,):
    print('Context::init()')
    return

  def set_strategy(self, strategy):
    self.strategy = strategy

  def action(self):
    self.strategy.run()