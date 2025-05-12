void SysTick_Handler(void)
{
  HAL_IncTick();  // Required for HAL timing

  static uint32_t count_sys = 0;

  if (++count_sys >= 2000)  // 2000 ms = 2 seconds
  {
    HAL_GPIO_TogglePin(Green_Led_GPIO_Port, Green_Led_Pin);
    count_sys = 0;
  }
}
