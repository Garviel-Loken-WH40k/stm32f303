MEMORY
{
  FLASH (rx)      : ORIGIN = 0x08000000, LENGTH = 128K
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 40K
}

SECTIONS
{
  .text :
  {
    KEEP(*(.isr_vector))
    *(.text*)
    *(.rodata*)
  } > FLASH

  .data : 
  {
    *(.data*)
  } > RAM AT > FLASH

  .bss :
  {
    *(.bss*)
    *(.bss.*)
  } > RAM

  _estack = ORIGIN(RAM) + LENGTH(RAM);
  _sdata = .;
  _edata = . + SIZEOF(.data);
  _sbss = .;
  _ebss = . + SIZEOF(.bss);
}