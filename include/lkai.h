// SPDX-License-Identifier: GPL-2.0
/*
 * LKAI - Kernel AI Interface
 *
 * Header file for LKAI kernel module
 */

#ifndef _LKAI_H
#define _LKAI_H

#include <linux/types.h>

/* Version */
#define LKAI_VERSION "0.1.0"

/* Fixed-point arithmetic parameters */
#define LKAI_FIXED_SHIFT 16
typedef s32 lkai_fixed_t;

/* Maximum tensor dimensions */
#define LKAI_MAX_TENSOR_DIMS 4
#define LKAI_MAX_TENSOR_SIZE (1024 * 1024)  /* 1M elements */

/* Tensor structure */
struct lkai_tensor {
    u32 ndims;
    u32 shape[LKAI_MAX_TENSOR_DIMS];
    u32 strides[LKAI_MAX_TENSOR_DIMS];
    size_t size;
    lkai_fixed_t *data;
};

/* Status codes */
#define LKAI_OK 0
#define LKAI_ERROR -1

/* Function prototypes */
int lkai_tensor_alloc(struct lkai_tensor *t, u32 ndims, const u32 *shape);
void lkai_tensor_free(struct lkai_tensor *t);
int lkai_tensor_matmul(struct lkai_tensor *out, const struct lkai_tensor *a, const struct lkai_tensor *b);
void lkai_tensor_relu(struct lkai_tensor *t);
int lkai_tensor_add(struct lkai_tensor *out, const struct lkai_tensor *a, const struct lkai_tensor *b);

#endif /* _LKAI_H */
