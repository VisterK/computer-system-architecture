global ComplexToReal
global FractionToReal
global PolarToReal
global NumberToReal
global sort

extern sqrt

SECTION .text

ComplexToReal:
        push    rbp                                     
        mov     rbp, rsp                                
        sub     rsp, 16                                 
        mov     qword [rbp-8H], rdi                     
        mov     rax, qword [rbp-8H]                     
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm1, xmm1, dword [rbp-0CH]           
        mov     rax, qword [rbp-8H]                     
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           
        vmulsd  xmm1, xmm1, xmm0                        
        mov     rax, qword [rbp-8H]                     
        add     rax, 4                                  
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm2, xmm2, dword [rbp-0CH]           
        mov     rax, qword [rbp-8H]                     
        add     rax, 4                                  
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           
        vmulsd  xmm0, xmm2, xmm0                        
        vaddsd  xmm0, xmm1, xmm0
        leave                                           
        ret                                             


FractionToReal:
        push    rbp                                     
        mov     rbp, rsp                                
        mov     qword [rbp-8H], rdi                     
        mov     rax, qword [rbp-8H]                     
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           
        mov     rax, qword [rbp-8H]                     
        add     rax, 4                                  
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm1, xmm1, dword [rbp-0CH]           
        vdivsd  xmm0, xmm0, xmm1                        
        pop     rbp                                     
        ret                                             


PolarToReal:
        push    rbp                                     
        mov     rbp, rsp                                
        mov     qword [rbp-8H], rdi                     
        mov     rax, qword [rbp-8H]                     
        add     rax, 4                                  
        mov     eax, dword [rax]                        
        mov     dword [rbp-0CH], eax                    
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           
        pop     rbp                                     
        ret                                             


NumberToReal:
        push    rbp                                     
        mov     rbp, rsp                                
        sub     rsp, 32                                 
        mov     qword [rbp-18H], rdi                    
        mov     rax, qword [rbp-18H]                    
        mov     eax, dword [rax]                        
        mov     dword [rbp-4H], eax                     
        cmp     dword [rbp-4H], 1                       
        jnz     .001                                   
        mov     rax, qword [rbp-18H]                    
        add     rax, 4                                  
        mov     rdi, rax                                
        call    ComplexToReal                           
        jmp     .004                                   

.001:  cmp     dword [rbp-4H], 2                       
        jnz     .002                                   
        mov     rax, qword [rbp-18H]                    
        add     rax, 4                                  
        mov     rdi, rax                                
        call    FractionToReal                          
        jmp     .004                                   

.002:  cmp     dword [rbp-4H], 3                       
        jnz     .003                                   
        mov     rax, qword [rbp-18H]                    
        add     rax, 4                                  
        mov     rdi, rax                                
        call    PolarToReal                             
        jmp     .004                                   

.003:  vxorpd  xmm0, xmm0, xmm0                        
.004:  leave                                           
        ret                                             


sort:   
        push    rbp                                     
        mov     rbp, rsp                                
        sub     rsp, 64                                 
        mov     qword [rbp-28H], rdi                    
        mov     dword [rbp-2CH], esi                    
        mov     dword [rbp-4H], 0                       
        mov     dword [rbp-8H], 0                       
        jmp     .011                                   

.005:  mov     eax, dword [rbp-4H]                     
        mov     dword [rbp-8H], eax                     
        mov     eax, dword [rbp-4H]                     
        inc     eax                                     
        mov     dword [rbp-0CH], eax                    
        jmp     .008                                   

.006:  mov     eax, dword [rbp-0CH]                    
        movsxd  rdx, eax                                
        mov     rax, rdx                                
        add     rax, rax                                
        add     rax, rdx                                
        shl     rax, 2                                  
        mov     rdx, rax                                
        mov     rax, qword [rbp-28H]                    
        add     rax, rdx                                
        mov     rdi, rax                                
        call    NumberToReal                            
        vmovsd  qword [rbp-38H], xmm0                   
        mov     eax, dword [rbp-8H]                     
        movsxd  rdx, eax                                
        mov     rax, rdx                                
        add     rax, rax                                
        add     rax, rdx                                
        shl     rax, 2                                  
        mov     rdx, rax                                
        mov     rax, qword [rbp-28H]                    
        add     rax, rdx                                
        mov     rdi, rax                                
        call    NumberToReal                            
        vcomisd xmm0, qword [rbp-38H]                   
        jc      .007                                   
        mov     eax, dword [rbp-0CH]                    
        mov     dword [rbp-8H], eax                     
.007:  inc     dword [rbp-0CH]                         
.008:  mov     eax, dword [rbp-0CH]                    
        cmp     eax, dword [rbp-2CH]                    
        jl      .006                                   
        mov     dword [rbp-10H], 0                      
        jmp     .010                                   

.009:  mov     edx, dword [rbp-4H]                     
        mov     eax, edx                                
        add     eax, eax                                
        add     eax, edx                                
        movsxd  rdx, eax                                
        mov     eax, dword [rbp-10H]                    
        cdqe                                            
        add     rax, rdx                                
        lea     rdx, [rax*4]                            
        mov     rax, qword [rbp-28H]                    
        add     rax, rdx                                
        mov     eax, dword [rax]                        
        mov     dword [rbp-14H], eax                    
        mov     edx, dword [rbp-8H]                     
        mov     eax, edx                                
        add     eax, eax                                
        add     eax, edx                                
        movsxd  rdx, eax                                
        mov     eax, dword [rbp-10H]                    
        cdqe                                            
        add     rax, rdx                                
        lea     rdx, [rax*4]                            
        mov     rax, qword [rbp-28H]                    
        lea     rcx, [rdx+rax]                          
        mov     edx, dword [rbp-4H]                     
        mov     eax, edx                                
        add     eax, eax                                
        add     eax, edx                                
        movsxd  rdx, eax                                
        mov     eax, dword [rbp-10H]                    
        cdqe                                            
        add     rax, rdx                                
        lea     rdx, [rax*4]                            
        mov     rax, qword [rbp-28H]                    
        add     rdx, rax                                
        mov     eax, dword [rcx]                        
        mov     dword [rdx], eax                        
        mov     edx, dword [rbp-8H]                     
        mov     eax, edx                                
        add     eax, eax                                
        add     eax, edx                                
        movsxd  rdx, eax                                
        mov     eax, dword [rbp-10H]                    
        cdqe                                            
        add     rax, rdx                                
        lea     rdx, [rax*4]                            
        mov     rax, qword [rbp-28H]                    
        add     rdx, rax                                
        mov     eax, dword [rbp-14H]                    
        mov     dword [rdx], eax                        
        inc     dword [rbp-10H]                         
.010:  cmp     dword [rbp-10H], 2                      
        jle     .009                                   
        inc     dword [rbp-4H]                          
.011:  mov     eax, dword [rbp-4H]                     
        cmp     eax, dword [rbp-2CH]                    
        jl      .005                                   
        nop                                             
        nop                                             
        leave                                           
        ret                                             

