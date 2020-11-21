
extern int printf$ii(void *, void *);
extern double __builtin_fabs(double);
extern unsigned char __builtin_volatile_read_int8unsigned(void *);
extern signed char __builtin_volatile_read_int8signed(void *);
extern unsigned short __builtin_volatile_read_int16unsigned(void *);
extern short __builtin_volatile_read_int16signed(void *);
extern int __builtin_volatile_read_int32(void *);
extern float __builtin_volatile_read_float32(void *);
extern double __builtin_volatile_read_float64(void *);
extern void *__builtin_volatile_read_pointer(void *);
extern void __builtin_volatile_write_int8unsigned(void *, unsigned char);
extern void __builtin_volatile_write_int8signed(void *, signed char);
extern void __builtin_volatile_write_int16unsigned(void *, unsigned short);
extern void __builtin_volatile_write_int16signed(void *, short);
extern void __builtin_volatile_write_int32(void *, int);
extern void __builtin_volatile_write_float32(void *, float);
extern void __builtin_volatile_write_float64(void *, double);
extern void __builtin_volatile_write_pointer(void *, void *);
extern void __builtin_memcpy(void *, void *, unsigned int);
extern void __builtin_memcpy_words(void *, void *, unsigned int);
extern void __builtin_annotation(unsigned char *);
extern double __builtin_fsqrt(double);
extern double __builtin_fmax(double, double);
extern double __builtin_fmin(double, double);
extern void abort(void);
extern void __assert_fail(unsigned char *, unsigned char *, unsigned int, unsigned char *);
