# SEL0433_PROJETO_3
# Conceitos Utilizados no Projeto

## 1. ESP32 DevKit

A ESP32 DevKit é uma placa de desenvolvimento baseada no microcontrolador ESP32, desenvolvida pela Espressif. Ela possui processador de 32 bits, conectividade Wi-Fi e Bluetooth integradas, diversos pinos de entrada e saída (GPIOs), conversores analógico-digitais (ADC), módulos de PWM por hardware e diversos periféricos que permitem o desenvolvimento de sistemas embarcados.

Neste projeto, a ESP32 foi utilizada para realizar o controle PWM de um LED RGB e de um servomotor, além de efetuar a leitura de sinais analógicos por meio do ADC e enviar informações pela comunicação serial.

---

# 2. Modulação por Largura de Pulso (PWM)

PWM (Pulse Width Modulation) é uma técnica utilizada para controlar a potência média fornecida a um dispositivo através da variação da largura do pulso de um sinal digital.

Embora a tensão aplicada permaneça constante, o tempo em que o sinal permanece em nível lógico alto pode ser alterado, permitindo controlar dispositivos como LEDs, motores DC e servomotores.

Os principais parâmetros do PWM são:

* Frequência
* Duty Cycle

---

# 3. Duty Cycle

O Duty Cycle representa a porcentagem do período em que o sinal permanece em nível alto.

Sua expressão é dada por:

[
Duty=\frac{T_{ON}}{T}\times100%
]

onde:

* (T_{ON}) é o tempo em nível alto;
* (T) é o período total do sinal.

Exemplos:

| Duty Cycle | Comportamento                 |
| ---------- | ----------------------------- |
| 0%         | Sempre desligado              |
| 25%        | Ligado durante 25% do período |
| 50%        | Ligado metade do tempo        |
| 75%        | Ligado durante 75% do período |
| 100%       | Sempre ligado                 |

No LED RGB, o duty cycle controla a intensidade luminosa de cada cor.

---

# 4. Frequência do PWM

A frequência corresponde ao número de ciclos PWM gerados por segundo.

É calculada por:

[
f=\frac{1}{T}
]

No controle do LED RGB foi utilizada uma frequência de **5 kHz**, conforme especificado no enunciado.

Já no servomotor, a frequência normalmente utilizada é de aproximadamente **50 Hz**, padrão adotado pela biblioteca ESP32Servo.

---

# 5. Resolução do PWM

A resolução define quantos níveis diferentes de duty cycle podem ser utilizados.

Neste projeto foi empregada resolução de **8 bits**, permitindo:

[
2^8=256
]

níveis distintos.

Assim, o duty cycle varia entre:

* 0
* 255

Quanto maior a resolução, mais preciso é o controle da intensidade luminosa ou da posição do atuador.

---

# 6. Biblioteca LEDC

A biblioteca LEDC (LED Control PWM) é o módulo nativo da ESP32 responsável pela geração de sinais PWM utilizando hardware dedicado.

Ela permite configurar:

* frequência;
* resolução;
* canais independentes de PWM.

No projeto, foram utilizados três canais independentes para controlar:

* Vermelho;
* Verde;
* Azul.

Cada canal possui um duty cycle próprio, permitindo gerar diferentes combinações de cores.

---

# 7. LED RGB

O LED RGB possui três LEDs internos:

* Vermelho (Red)
* Verde (Green)
* Azul (Blue)

Controlando a intensidade de cada cor através do PWM é possível produzir diversas combinações de cores.

Foi utilizado um LED RGB de cátodo comum, no qual o terminal comum é conectado ao GND.

Cada cor foi ligada à ESP32 através de um resistor de 220 Ω para limitar a corrente elétrica.

---

# 8. Comunicação Serial (UART)

A UART (Universal Asynchronous Receiver/Transmitter) é um protocolo de comunicação serial amplamente utilizado em sistemas embarcados.

Neste projeto foi utilizada a taxa de transmissão de **115200 baud**, permitindo acompanhar em tempo real:

* duty cycle;
* incrementos utilizados;
* valores lidos pelo ADC;
* ângulo do servomotor.

A comunicação serial facilita a depuração e a validação do funcionamento do sistema.

---

# 9. Conversor Analógico-Digital (ADC)

O ADC (Analog-to-Digital Converter) converte uma tensão analógica em um valor digital.

Na ESP32, o ADC possui resolução de **12 bits**, produzindo valores entre:

* 0
* 4095

No projeto, o ADC foi utilizado para ler a posição do potenciômetro.

Posteriormente, esses valores foram convertidos em ângulos entre 0° e 180°, permitindo controlar o servomotor.

---

# 10. Potenciômetro

O potenciômetro é um resistor variável utilizado como divisor de tensão.

Ao girar seu eixo, a tensão presente no terminal central varia continuamente entre 0 V e 3,3 V.

Essa tensão é lida pelo ADC da ESP32, permitindo controlar a posição do servomotor de forma manual.

---

# 11. Servomotor

O servomotor é um atuador capaz de posicionar seu eixo em um ângulo específico.

Seu controle é realizado por PWM.

A largura do pulso determina a posição do eixo:

* aproximadamente 500 µs → 0°
* aproximadamente 1500 µs → 90°
* aproximadamente 2500 µs → 180°

A biblioteca ESP32Servo realiza automaticamente a geração desses pulsos.

---

# 12. Biblioteca ESP32Servo

A biblioteca ESP32Servo simplifica o controle de servomotores na ESP32.

Ela encapsula toda a geração do sinal PWM necessário para movimentar o servo.

As principais funções utilizadas foram:

* `attach()` – associa o servo ao pino escolhido;
* `write()` – define o ângulo desejado.

---

# 13. Simulador Wokwi

O Wokwi é um ambiente de simulação de sistemas embarcados que permite desenvolver e testar projetos sem a necessidade de hardware físico.

No projeto, o simulador foi utilizado para:

* montar o circuito;
* testar o LED RGB;
* controlar o servomotor;
* visualizar a saída serial;
* validar o funcionamento do software.

---

# 14. Considerações Finais

Durante o desenvolvimento foram aplicados diversos conceitos fundamentais de sistemas embarcados, como geração de PWM, leitura analógica utilizando ADC, comunicação serial e controle de atuadores. A utilização das bibliotecas LEDC e ESP32Servo simplificou a implementação, enquanto o ambiente Wokwi possibilitou validar o funcionamento do hardware e do software antes de uma eventual montagem física.
