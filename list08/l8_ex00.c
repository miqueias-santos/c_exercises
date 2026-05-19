#include <stdio.h>
#define N_BITS 8
struct BitField {
	unsigned int erro : 1;
	unsigned int modo : 3;
	unsigned int leitura : 4;
};

union signal_sensor {
	unsigned char raw;
	struct BitField status;
};

void recieve_bits(unsigned char *v);
int calculate_raw(const unsigned char *v, int len);
void evaluate_sensor(const unsigned char *v, union signal_sensor *sensor);
void set_output(const unsigned char *v, union signal_sensor *sensor);

int main() {
	unsigned char bits[N_BITS]; 
	union signal_sensor sensor;

	recieve_bits(bits);
    	
	sensor.raw = calculate_raw(bits, N_BITS);
	printf("Byte bruto: %d | ", sensor.raw);

	evaluate_sensor(bits, &sensor);
	printf("Erro: %d | Modo: %d | Leitura: %d\n", sensor.status.erro, sensor.status.modo, sensor.status.leitura);


   
    return 0;
}

void recieve_bits(unsigned char *v) {

	for (int i = 0; i < N_BITS; i++) {
		scanf(" %c", v + i);	
	}
}

int calculate_raw(const unsigned char *v, int len) {
	
	int raw = 0;
	for (int i = 0; i < len; i++) {
		if (v[len - 1 - i] == '1') raw += (1 << i);
	}
	return raw;
}

void evaluate_sensor(const unsigned char *v, union signal_sensor *sensor) {
	
	sensor->status.erro = v[N_BITS - 1];
	sensor->status.modo = calculate_raw(v + 4, 3);
	sensor->status.leitura = calculate_raw(v, 4);

}


