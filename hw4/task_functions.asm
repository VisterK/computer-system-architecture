global ComplexToReal
global FractionToReal
global PolarToReal
global NumberToReal
global sort

extern sqrt

SECTION .text

ComplexToReal:; Function begin
        push    rbp                                     ; 0004 _ 55
        mov     rbp, rsp                                ; 0005 _ 48: 89. E5
        sub     rsp, 16                                 ; 0008 _ 48: 83. EC, 10
        mov     qword [rbp-8H], rdi                     ; 000C _ 48: 89. 7D, F8
        mov     rax, qword [rbp-8H]                     ; 0010 _ 48: 8B. 45, F8
        mov     eax, dword [rax]                        ; 0014 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 0016 _ 89. 45, F4
        vcvtsi2sd xmm1, xmm1, dword [rbp-0CH]           ; 0019 _ C5 F3: 2A. 4D, F4
        mov     rax, qword [rbp-8H]                     ; 001E _ 48: 8B. 45, F8
        mov     eax, dword [rax]                        ; 0022 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 0024 _ 89. 45, F4
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           ; 0027 _ C5 FB: 2A. 45, F4
        vmulsd  xmm1, xmm1, xmm0                        ; 002C _ C5 F3: 59. C8
        mov     rax, qword [rbp-8H]                     ; 0030 _ 48: 8B. 45, F8
        add     rax, 4                                  ; 0034 _ 48: 83. C0, 04
        mov     eax, dword [rax]                        ; 0038 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 003A _ 89. 45, F4
        vcvtsi2sd xmm2, xmm2, dword [rbp-0CH]           ; 003D _ C5 EB: 2A. 55, F4
        mov     rax, qword [rbp-8H]                     ; 0042 _ 48: 8B. 45, F8
        add     rax, 4                                  ; 0046 _ 48: 83. C0, 04
        mov     eax, dword [rax]                        ; 004A _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 004C _ 89. 45, F4
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           ; 004F _ C5 FB: 2A. 45, F4
        vmulsd  xmm0, xmm2, xmm0                        ; 0054 _ C5 EB: 59. C0
        vaddsd  xmm0, xmm1, xmm0                        ; 0058 _ C5 F3: 58. C0
        ;call    sqrt                                    ; 005C _ E8, 00000000(PLT r)
        leave                                           ; 0061 _ C9
        ret                                             ; 0062 _ C3
; ComplexToReal End of function

FractionToReal:; Function begin
        push    rbp                                     ; 0067 _ 55
        mov     rbp, rsp                                ; 0068 _ 48: 89. E5
        mov     qword [rbp-8H], rdi                     ; 006B _ 48: 89. 7D, F8
        mov     rax, qword [rbp-8H]                     ; 006F _ 48: 8B. 45, F8
        mov     eax, dword [rax]                        ; 0073 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 0075 _ 89. 45, F4
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           ; 0078 _ C5 FB: 2A. 45, F4
        mov     rax, qword [rbp-8H]                     ; 007D _ 48: 8B. 45, F8
        add     rax, 4                                  ; 0081 _ 48: 83. C0, 04
        mov     eax, dword [rax]                        ; 0085 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 0087 _ 89. 45, F4
        vcvtsi2sd xmm1, xmm1, dword [rbp-0CH]           ; 008A _ C5 F3: 2A. 4D, F4
        vdivsd  xmm0, xmm0, xmm1                        ; 008F _ C5 FB: 5E. C1
        pop     rbp                                     ; 0093 _ 5D
        ret                                             ; 0094 _ C3
; FractionToReal End of function

PolarToReal:; Function begin
        push    rbp                                     ; 0099 _ 55
        mov     rbp, rsp                                ; 009A _ 48: 89. E5
        mov     qword [rbp-8H], rdi                     ; 009D _ 48: 89. 7D, F8
        mov     rax, qword [rbp-8H]                     ; 00A1 _ 48: 8B. 45, F8
        add     rax, 4                                  ; 00A5 _ 48: 83. C0, 04
        mov     eax, dword [rax]                        ; 00A9 _ 8B. 00
        mov     dword [rbp-0CH], eax                    ; 00AB _ 89. 45, F4
        vcvtsi2sd xmm0, xmm0, dword [rbp-0CH]           ; 00AE _ C5 FB: 2A. 45, F4
        pop     rbp                                     ; 00B3 _ 5D
        ret                                             ; 00B4 _ C3
; PolarToReal End of function

NumberToReal:; Function begin
        push    rbp                                     ; 00B9 _ 55
        mov     rbp, rsp                                ; 00BA _ 48: 89. E5
        sub     rsp, 32                                 ; 00BD _ 48: 83. EC, 20
        mov     qword [rbp-18H], rdi                    ; 00C1 _ 48: 89. 7D, E8
        mov     rax, qword [rbp-18H]                    ; 00C5 _ 48: 8B. 45, E8
        mov     eax, dword [rax]                        ; 00C9 _ 8B. 00
        mov     dword [rbp-4H], eax                     ; 00CB _ 89. 45, FC
        cmp     dword [rbp-4H], 1                       ; 00CE _ 83. 7D, FC, 01
        jnz     .001                                   ; 00D2 _ 75, 12
        mov     rax, qword [rbp-18H]                    ; 00D4 _ 48: 8B. 45, E8
        add     rax, 4                                  ; 00D8 _ 48: 83. C0, 04
        mov     rdi, rax                                ; 00DC _ 48: 89. C7
        call    ComplexToReal                           ; 00DF _ E8, 00000000(PLT r)
        jmp     .004                                   ; 00E4 _ EB, 34

.001:  cmp     dword [rbp-4H], 2                       ; 00E6 _ 83. 7D, FC, 02
        jnz     .002                                   ; 00EA _ 75, 12
        mov     rax, qword [rbp-18H]                    ; 00EC _ 48: 8B. 45, E8
        add     rax, 4                                  ; 00F0 _ 48: 83. C0, 04
        mov     rdi, rax                                ; 00F4 _ 48: 89. C7
        call    FractionToReal                          ; 00F7 _ E8, 00000000(PLT r)
        jmp     .004                                   ; 00FC _ EB, 1C

.002:  cmp     dword [rbp-4H], 3                       ; 00FE _ 83. 7D, FC, 03
        jnz     .003                                   ; 0102 _ 75, 12
        mov     rax, qword [rbp-18H]                    ; 0104 _ 48: 8B. 45, E8
        add     rax, 4                                  ; 0108 _ 48: 83. C0, 04
        mov     rdi, rax                                ; 010C _ 48: 89. C7
        call    PolarToReal                             ; 010F _ E8, 00000000(PLT r)
        jmp     .004                                   ; 0114 _ EB, 04

.003:  vxorpd  xmm0, xmm0, xmm0                        ; 0116 _ C5 F9: 57. C0
.004:  leave                                           ; 011A _ C9
        ret                                             ; 011B _ C3
; NumberToReal End of function

sort:   ; Function begin
        push    rbp                                     ; 0120 _ 55
        mov     rbp, rsp                                ; 0121 _ 48: 89. E5
        sub     rsp, 64                                 ; 0124 _ 48: 83. EC, 40
        mov     qword [rbp-28H], rdi                    ; 0128 _ 48: 89. 7D, D8
        mov     dword [rbp-2CH], esi                    ; 012C _ 89. 75, D4
        mov     dword [rbp-4H], 0                       ; 012F _ C7. 45, FC, 00000000
        mov     dword [rbp-8H], 0                       ; 0136 _ C7. 45, F8, 00000000
        jmp     .011                                   ; 013D _ E9, 0000012E

.005:  mov     eax, dword [rbp-4H]                     ; 0142 _ 8B. 45, FC
        mov     dword [rbp-8H], eax                     ; 0145 _ 89. 45, F8
        mov     eax, dword [rbp-4H]                     ; 0148 _ 8B. 45, FC
        inc     eax                                     ; 014B _ FF. C0
        mov     dword [rbp-0CH], eax                    ; 014D _ 89. 45, F4
        jmp     .008                                   ; 0150 _ EB, 5F

.006:  mov     eax, dword [rbp-0CH]                    ; 0152 _ 8B. 45, F4
        movsxd  rdx, eax                                ; 0155 _ 48: 63. D0
        mov     rax, rdx                                ; 0158 _ 48: 89. D0
        add     rax, rax                                ; 015B _ 48: 01. C0
        add     rax, rdx                                ; 015E _ 48: 01. D0
        shl     rax, 2                                  ; 0161 _ 48: C1. E0, 02
        mov     rdx, rax                                ; 0165 _ 48: 89. C2
        mov     rax, qword [rbp-28H]                    ; 0168 _ 48: 8B. 45, D8
        add     rax, rdx                                ; 016C _ 48: 01. D0
        mov     rdi, rax                                ; 016F _ 48: 89. C7
        call    NumberToReal                            ; 0172 _ E8, 00000000(PLT r)
        vmovsd  qword [rbp-38H], xmm0                   ; 0177 _ C5 FB: 11. 45, C8
        mov     eax, dword [rbp-8H]                     ; 017C _ 8B. 45, F8
        movsxd  rdx, eax                                ; 017F _ 48: 63. D0
        mov     rax, rdx                                ; 0182 _ 48: 89. D0
        add     rax, rax                                ; 0185 _ 48: 01. C0
        add     rax, rdx                                ; 0188 _ 48: 01. D0
        shl     rax, 2                                  ; 018B _ 48: C1. E0, 02
        mov     rdx, rax                                ; 018F _ 48: 89. C2
        mov     rax, qword [rbp-28H]                    ; 0192 _ 48: 8B. 45, D8
        add     rax, rdx                                ; 0196 _ 48: 01. D0
        mov     rdi, rax                                ; 0199 _ 48: 89. C7
        call    NumberToReal                            ; 019C _ E8, 00000000(PLT r)
        vcomisd xmm0, qword [rbp-38H]                   ; 01A1 _ C5 F9: 2F. 45, C8
        jc      .007                                   ; 01A6 _ 72, 06
        mov     eax, dword [rbp-0CH]                    ; 01A8 _ 8B. 45, F4
        mov     dword [rbp-8H], eax                     ; 01AB _ 89. 45, F8
.007:  inc     dword [rbp-0CH]                         ; 01AE _ FF. 45, F4
.008:  mov     eax, dword [rbp-0CH]                    ; 01B1 _ 8B. 45, F4
        cmp     eax, dword [rbp-2CH]                    ; 01B4 _ 3B. 45, D4
        jl      .006                                   ; 01B7 _ 7C, 99
        mov     dword [rbp-10H], 0                      ; 01B9 _ C7. 45, F0, 00000000
        jmp     .010                                   ; 01C0 _ E9, 0000009E

.009:  mov     edx, dword [rbp-4H]                     ; 01C5 _ 8B. 55, FC
        mov     eax, edx                                ; 01C8 _ 89. D0
        add     eax, eax                                ; 01CA _ 01. C0
        add     eax, edx                                ; 01CC _ 01. D0
        movsxd  rdx, eax                                ; 01CE _ 48: 63. D0
        mov     eax, dword [rbp-10H]                    ; 01D1 _ 8B. 45, F0
        cdqe                                            ; 01D4 _ 48: 98
        add     rax, rdx                                ; 01D6 _ 48: 01. D0
        lea     rdx, [rax*4]                            ; 01D9 _ 48: 8D. 14 85, 00000000
        mov     rax, qword [rbp-28H]                    ; 01E1 _ 48: 8B. 45, D8
        add     rax, rdx                                ; 01E5 _ 48: 01. D0
        mov     eax, dword [rax]                        ; 01E8 _ 8B. 00
        mov     dword [rbp-14H], eax                    ; 01EA _ 89. 45, EC
        mov     edx, dword [rbp-8H]                     ; 01ED _ 8B. 55, F8
        mov     eax, edx                                ; 01F0 _ 89. D0
        add     eax, eax                                ; 01F2 _ 01. C0
        add     eax, edx                                ; 01F4 _ 01. D0
        movsxd  rdx, eax                                ; 01F6 _ 48: 63. D0
        mov     eax, dword [rbp-10H]                    ; 01F9 _ 8B. 45, F0
        cdqe                                            ; 01FC _ 48: 98
        add     rax, rdx                                ; 01FE _ 48: 01. D0
        lea     rdx, [rax*4]                            ; 0201 _ 48: 8D. 14 85, 00000000
        mov     rax, qword [rbp-28H]                    ; 0209 _ 48: 8B. 45, D8
        lea     rcx, [rdx+rax]                          ; 020D _ 48: 8D. 0C 02
        mov     edx, dword [rbp-4H]                     ; 0211 _ 8B. 55, FC
        mov     eax, edx                                ; 0214 _ 89. D0
        add     eax, eax                                ; 0216 _ 01. C0
        add     eax, edx                                ; 0218 _ 01. D0
        movsxd  rdx, eax                                ; 021A _ 48: 63. D0
        mov     eax, dword [rbp-10H]                    ; 021D _ 8B. 45, F0
        cdqe                                            ; 0220 _ 48: 98
        add     rax, rdx                                ; 0222 _ 48: 01. D0
        lea     rdx, [rax*4]                            ; 0225 _ 48: 8D. 14 85, 00000000
        mov     rax, qword [rbp-28H]                    ; 022D _ 48: 8B. 45, D8
        add     rdx, rax                                ; 0231 _ 48: 01. C2
        mov     eax, dword [rcx]                        ; 0234 _ 8B. 01
        mov     dword [rdx], eax                        ; 0236 _ 89. 02
        mov     edx, dword [rbp-8H]                     ; 0238 _ 8B. 55, F8
        mov     eax, edx                                ; 023B _ 89. D0
        add     eax, eax                                ; 023D _ 01. C0
        add     eax, edx                                ; 023F _ 01. D0
        movsxd  rdx, eax                                ; 0241 _ 48: 63. D0
        mov     eax, dword [rbp-10H]                    ; 0244 _ 8B. 45, F0
        cdqe                                            ; 0247 _ 48: 98
        add     rax, rdx                                ; 0249 _ 48: 01. D0
        lea     rdx, [rax*4]                            ; 024C _ 48: 8D. 14 85, 00000000
        mov     rax, qword [rbp-28H]                    ; 0254 _ 48: 8B. 45, D8
        add     rdx, rax                                ; 0258 _ 48: 01. C2
        mov     eax, dword [rbp-14H]                    ; 025B _ 8B. 45, EC
        mov     dword [rdx], eax                        ; 025E _ 89. 02
        inc     dword [rbp-10H]                         ; 0260 _ FF. 45, F0
.010:  cmp     dword [rbp-10H], 2                      ; 0263 _ 83. 7D, F0, 02
        jle     .009                                   ; 0267 _ 0F 8E, FFFFFF58
        inc     dword [rbp-4H]                          ; 026D _ FF. 45, FC
.011:  mov     eax, dword [rbp-4H]                     ; 0270 _ 8B. 45, FC
        cmp     eax, dword [rbp-2CH]                    ; 0273 _ 3B. 45, D4
        jl      .005                                   ; 0276 _ 0F 8C, FFFFFEC6
        nop                                             ; 027C _ 90
        nop                                             ; 027D _ 90
        leave                                           ; 027E _ C9
        ret                                             ; 027F _ C3
; sort End of function