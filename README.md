# Проект для Milandr K1986BE92QI для VSCode + JLink + Linux 

Пустой настроенный проект для K1986BE92QI для VSCode + JLink + Linux.
В проект включены все библиотеки CMSIS и STD и все остальные файлы для настройки проекта.
## Требуемые пакеты
Для работы требуются пакеты:
```
sudo apt update
sudo apt install gcc
sudo apt install gcc-arm-none-eabi
```

Так-же необходимо установить J-Link, актуальную версию можно взять [здесь](https://www.segger.com/downloads/jlink/#J-LinkSoftwareAndDocumentationPack). 

## Настройка J-Link

J-Link не поддерживает миландры из коробки, необходимо его научить
1. Скачайте пак миландра с [сайта миландра](https://ic.milandr.ru/soft/) (приложен к проекту)
2. Файл `1986BE9x.FLM` из архиве поместите в папку SEGGER: `home/<username>/.config/SEGGER/JLinkDevices/Milandr` 
3. Добавьте строки в файл `Devices.xml`, который можно обычно найти по адресу `/home/<username>/.config/SEGGER/JLinkDevices/Devices.xml`:
    ```xml
    <Database>
    <Device>
        <ChipInfo Vendor="Milandr"
            Name="K1986BE92QI"
            WorkRAMAddr="0x20000000"
            WorkRAMSize="0x8000"
            Core="JLINK_CORE_CORTEX_M3"/>
            <FlashBankInfo Name="K1986BE92QI Flash"
            BaseAddr="0x8000000"
            MaxSize="0x20000" 
    Loader="/home/<username>/.config/SEGGER/JLinkDevices/Milandr/MDR32F9Q2I.FLM"
            LoaderType="FLASH_ALGO_TYPE_OPEN"
            AlwaysPresent="1" />
    </Device>
    </Database>
    ```
    Замените адрес .FLM на свой.  Может быть, что файла `Devices.xml` нет, тогда создайте его

Теперь K1986BE92 должен появиться в списке устройств. Можно легко проверить:
```bash
JLinkExe
connect
?
```
Откроется окно выбора устройства, K1986BE92 должен быть в списке.

## VScode

Требуются расширения:
-  C/C++
-  Cortex Debug
-  Makefile Tools


Комплиляция стандартными средствами VSCode через `Ctrl+Shift+B` или `Ctrl+Shift+P`, и далее `Run task:`. 
Дебаг кнопкой дебага в боковом меню
