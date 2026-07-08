# SEL0433_PROJETO_3
# Desenvolvimento do Projeto

## Parte 1 – Controle PWM de LED RGB

### Objetivo

Nesta etapa foi desenvolvido um sistema para controle da intensidade luminosa de um LED RGB de cátodo comum utilizando a placa ESP32 DevKit. Cada uma das três cores (vermelho, verde e azul) foi controlada de forma independente por meio da técnica de Modulação por Largura de Pulso (PWM), utilizando a biblioteca nativa LEDC da ESP32.

A frequência do PWM foi configurada para **5 kHz** com resolução de **8 bits**, conforme especificado no enunciado. Dessa forma, cada canal possui 256 níveis possíveis de duty cycle (0 a 255), permitindo o ajuste preciso da intensidade luminosa de cada componente de cor.

Os duty cycles das três cores foram incrementados continuamente, porém utilizando velocidades diferentes para cada canal. Foram definidos incrementos de 15 unidades para o vermelho, 5 unidades para o verde e 10 unidades para o azul. Quando um canal atinge o valor máximo (255), seu duty cycle retorna para zero e o processo continua em execução contínua.

Durante toda a execução do programa, a ESP32 envia pela interface serial os valores de duty cycle aplicados em cada canal, permitindo acompanhar em tempo real o funcionamento do sistema.

---

### Bibliotecas utilizadas

#### Biblioteca LEDC

A biblioteca LEDC é responsável pela geração dos sinais PWM utilizando os periféricos de hardware da ESP32. Sua utilização permite gerar sinais PWM com frequência e resolução configuráveis, sem sobrecarregar o processador.

Funções utilizadas:

* `ledcAttach()` — configura o pino para operar com PWM.
* `ledcWrite()` — atualiza o duty cycle aplicado ao canal.

---

### Principais trechos do código

#### Inicialização da comunicação serial

```cpp
Serial.begin(115200);
```

Inicializa a interface UART utilizada para monitorar os valores do PWM.

---

#### Configuração do PWM

```cpp
ledcAttach(RED_PIN, PWM_FREQ, PWM_RES);
ledcAttach(GREEN_PIN, PWM_FREQ, PWM_RES);
ledcAttach(BLUE_PIN, PWM_FREQ, PWM_RES);
```

Configura três canais PWM independentes, um para cada cor do LED RGB.

---

#### Atualização dos duty cycles

```cpp
ledcWrite(RED_PIN, redDuty);
ledcWrite(GREEN_PIN, greenDuty);
ledcWrite(BLUE_PIN, blueDuty);
```

Aplica os valores calculados de duty cycle aos três canais PWM.

---

### Conceitos envolvidos

* Modulação por largura de pulso (PWM);
* Duty Cycle;
* Frequência do PWM;
* Resolução de 8 bits;
* Biblioteca LEDC;
* Comunicação Serial (UART);
* Controle independente dos canais PWM.

---

### Resultados

A simulação demonstrou que o LED RGB variou continuamente suas cores conforme os incrementos programados. Como cada canal possui uma velocidade de incremento diferente, diversas combinações de cores foram produzidas ao longo da execução. O monitor serial apresentou corretamente os valores de duty cycle aplicados em cada cor, permitindo validar o funcionamento do sistema.

---

## Parte 2 – Controle de Servomotor utilizando Potenciômetro

### Objetivo

Na segunda etapa foi desenvolvido um sistema para controle da posição angular de um servomotor utilizando um potenciômetro conectado à entrada analógica da ESP32.

O potenciômetro funciona como um divisor de tensão, produzindo um sinal analógico proporcional à posição do seu eixo. Esse sinal é convertido pelo conversor analógico-digital (ADC) da ESP32, gerando valores entre 0 e 4095. Em seguida, esses valores são convertidos para ângulos entre 0° e 180°, que são enviados ao servomotor utilizando a biblioteca ESP32Servo.

O monitor serial apresenta continuamente os valores lidos pelo ADC e o ângulo correspondente, permitindo verificar o correto funcionamento da conversão.

---

### Bibliotecas utilizadas

#### Biblioteca ESP32Servo

A biblioteca ESP32Servo simplifica o controle de servomotores na ESP32, gerando automaticamente os pulsos PWM necessários para o posicionamento do eixo.

Funções utilizadas:

* `attach()` — associa o servomotor ao pino da ESP32.
* `write()` — posiciona o servo no ângulo especificado.

---

### Principais trechos do código

#### Leitura do potenciômetro

```cpp
int adc = analogRead(potPin);
```

Realiza a leitura do sinal analógico gerado pelo potenciômetro.

---

#### Conversão da leitura para ângulo

```cpp
int angulo = map(adc, 0, 4095, 0, 180);
```

Converte a faixa do ADC (0 a 4095) para o intervalo de operação do servomotor (0° a 180°).

---

#### Controle do servomotor

```cpp
servo.write(angulo);
```

Posiciona o eixo do servomotor conforme o ângulo calculado.

---

### Conceitos envolvidos

* Conversão Analógico-Digital (ADC);
* Potenciômetro como divisor de tensão;
* Controle PWM de servomotores;
* Biblioteca ESP32Servo;
* Comunicação Serial (UART);
* Conversão de valores utilizando a função `map()`.

---

### Resultados

Durante os testes no simulador Wokwi, o servomotor acompanhou corretamente a posição do potenciômetro. À medida que o potenciômetro era ajustado, os valores do ADC variavam e eram convertidos em ângulos proporcionais entre 0° e 180°. O monitor serial apresentou continuamente as leituras do ADC e os respectivos ângulos, confirmando o correto funcionamento do sistema. Pequenas oscilações observadas nas leituras analógicas são esperadas devido às características do ADC e do ambiente de simulação.
