void Reset_Handler(void);
static void Default_Handler(void);
static void crt_init(void);
static void system_init(void);
extern int main(void);

/* Reserve stack */
#pragma DATA_SECTION(stack_mem, ".stack")    // separate memory location for stack
#define STACK_SIZE 128  // long words
long stack_mem[STACK_SIZE];  // 4 * STACK_SIZE bytes (512 bytes)

#pragma DATA_SECTION(vector_table, ".intvecs")
const long vector_table[] =        //32-bit entries
{
     (long) (stack_mem + STACK_SIZE),
     (long) Reset_Handler,
     (long) Default_Handler,        //Core Exceptions
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     (long) Default_Handler,
     // ignore peripheral exceptions
};

static void Default_Handler(void)
{
    while(1)
        ;
}

void Reset_Handler(void)
{
    crt_init();
    system_init();
    main();

    while(1)
        ;
}

static void crt_init()
{
    // initialize all initialized variables
    // zero-initialize all uinitialized variables
}

static void system_init()
{
    // clock init
    // memory init
    // FPU
}


