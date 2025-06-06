/**
  ******************************************************************************
  * @file    bilstm_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Sep  4 16:24:29 2024
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "bilstm_model.h"
#include "bilstm_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_bilstm_model
 
#undef AI_BILSTM_MODEL_MODEL_SIGNATURE
#define AI_BILSTM_MODEL_MODEL_SIGNATURE     "e3ce3a8f8afd1f23026084230cb93e46"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Sep  4 16:24:29 2024"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_BILSTM_MODEL_N_BATCHES
#define AI_BILSTM_MODEL_N_BATCHES         (1)

static ai_ptr g_bilstm_model_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_bilstm_model_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  re_lu_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 9, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_conv2d_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_conv2d_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_peephole_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 48, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_recurrent_params_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_peephole_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 192, AI_STATIC)
/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_1_kernel_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)
/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_1_recurrent_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)
/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 131072, AI_STATIC)
/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)
/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  dense_1_dense_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 9, AI_STATIC)
/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)
/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 112, AI_STATIC)
/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)
/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 4096, AI_STATIC)
/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv1d_conv2d_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_1_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 448, AI_STATIC)
/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  permute_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)
/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_output0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_output0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  bidirectional_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)
/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  backward_lstm_1_output0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  forward_lstm_1_output0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)
/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  bidirectional_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)
/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  dense_dense_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)
/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  re_lu_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &re_lu_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 9, 1, 1), AI_STRIDE_INIT(4, 4, 4, 36, 36),
  1, &dense_1_dense_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_conv2d_weights, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 4096, 1, 1, 8), AI_STRIDE_INIT(4, 4, 16384, 131072, 131072),
  1, &conv1d_conv2d_weights_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_conv2d_bias, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1d_conv2d_bias_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_kernel, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &backward_lstm_kernel_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_recurrent, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 16, 64, 1, 1), AI_STRIDE_INIT(4, 4, 64, 4096, 4096),
  1, &backward_lstm_recurrent_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_peephole, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 48), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &backward_lstm_peephole_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_bias, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &backward_lstm_bias_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_recurrent_params, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &backward_lstm_recurrent_params_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_kernel, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &forward_lstm_kernel_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_recurrent, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 16, 64, 1, 1), AI_STRIDE_INIT(4, 4, 64, 4096, 4096),
  1, &forward_lstm_recurrent_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_bias, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &forward_lstm_bias_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_kernel, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 32, 256, 1, 1), AI_STRIDE_INIT(4, 4, 128, 32768, 32768),
  1, &backward_lstm_1_kernel_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_recurrent, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 64, 256, 1, 1), AI_STRIDE_INIT(4, 4, 256, 65536, 65536),
  1, &backward_lstm_1_recurrent_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_peephole, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 192), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &backward_lstm_1_peephole_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_bias, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &backward_lstm_1_bias_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_1_kernel, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 32, 256, 1, 1), AI_STRIDE_INIT(4, 4, 128, 32768, 32768),
  1, &forward_lstm_1_kernel_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_1_recurrent, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 64, 256, 1, 1), AI_STRIDE_INIT(4, 4, 256, 65536, 65536),
  1, &forward_lstm_1_recurrent_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_1_bias, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &forward_lstm_1_bias_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_weights, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1024, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4096, 524288, 524288),
  1, &dense_dense_weights_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_bias, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_dense_bias_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_weights, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 128, 9, 1, 1), AI_STRIDE_INIT(4, 4, 512, 4608, 4608),
  1, &dense_1_dense_weights_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  dense_1_dense_bias, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 9, 1, 1), AI_STRIDE_INIT(4, 4, 4, 36, 36),
  1, &dense_1_dense_bias_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_scratch0, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &backward_lstm_scratch0_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_scratch0, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &forward_lstm_scratch0_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_scratch0, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1792, 1792),
  1, &backward_lstm_1_scratch0_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 4096, 1, 1), AI_STRIDE_INIT(4, 4, 4, 16384, 16384),
  1, &input_0_output_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv1d_conv2d_output, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1d_conv2d_output_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_1_scratch0, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 448, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1792, 1792),
  1, &forward_lstm_1_scratch0_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  permute_output, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 8), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &permute_output_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_output0, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 8), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &backward_lstm_output0_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_output0, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 8), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &forward_lstm_output0_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  bidirectional_output, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 8), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &bidirectional_output_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  backward_lstm_1_output0, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 8), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &backward_lstm_1_output0_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  forward_lstm_1_output0, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 8), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &forward_lstm_1_output0_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  bidirectional_1_output, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 8), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &bidirectional_1_output_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  bidirectional_1_output0, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4096, 4096),
  1, &bidirectional_1_output_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  dense_dense_output, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &dense_dense_output_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_1_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_1_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_1_dense_weights, &dense_1_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_1_dense_layer, 7,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_1_dense_chain,
  NULL, &dense_1_dense_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  re_lu_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &re_lu_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  re_lu_layer, 6,
  NL_TYPE, 0x0, NULL,
  nl, forward_relu,
  &re_lu_chain,
  NULL, &dense_1_dense_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_dense_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &bidirectional_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_dense_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_dense_weights, &dense_dense_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_dense_layer, 5,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense,
  &dense_dense_chain,
  NULL, &re_lu_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  bidirectional_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &forward_lstm_1_output0, &backward_lstm_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &bidirectional_1_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  bidirectional_1_layer, 3,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &bidirectional_1_chain,
  NULL, &dense_dense_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  forward_lstm_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &bidirectional_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &forward_lstm_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 9, &forward_lstm_1_kernel, &forward_lstm_1_recurrent, &backward_lstm_1_peephole, &forward_lstm_1_bias, NULL, &backward_lstm_recurrent_params, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &forward_lstm_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  forward_lstm_1_layer, 3,
  LSTM_TYPE, 0x0, NULL,
  lstm, forward_lstm,
  &forward_lstm_1_chain,
  NULL, &bidirectional_1_layer, AI_STATIC, 
  .n_units = 64, 
  .activation_nl = nl_func_tanh_array_f32, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .return_state = false, 
  .out_nl = nl_func_tanh_array_f32, 
  .recurrent_nl = nl_func_hard_sigmoid_array_f32, 
  .cell_clip = 3e+38, 
  .state = AI_HANDLE_PTR(NULL), 
  .init = AI_LAYER_FUNC(NULL), 
  .destroy = AI_LAYER_FUNC(NULL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  backward_lstm_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &bidirectional_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &backward_lstm_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 9, &backward_lstm_1_kernel, &backward_lstm_1_recurrent, &backward_lstm_1_peephole, &backward_lstm_1_bias, NULL, &backward_lstm_recurrent_params, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &backward_lstm_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  backward_lstm_1_layer, 3,
  LSTM_TYPE, 0x0, NULL,
  lstm, forward_lstm,
  &backward_lstm_1_chain,
  NULL, &forward_lstm_1_layer, AI_STATIC, 
  .n_units = 64, 
  .activation_nl = nl_func_tanh_array_f32, 
  .go_backwards = true, 
  .reverse_seq = true, 
  .return_state = false, 
  .out_nl = nl_func_tanh_array_f32, 
  .recurrent_nl = nl_func_hard_sigmoid_array_f32, 
  .cell_clip = 3e+38, 
  .state = AI_HANDLE_PTR(NULL), 
  .init = AI_LAYER_FUNC(NULL), 
  .destroy = AI_LAYER_FUNC(NULL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  bidirectional_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &forward_lstm_output0, &backward_lstm_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &bidirectional_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  bidirectional_layer, 2,
  CONCAT_TYPE, 0x0, NULL,
  concat, forward_concat,
  &bidirectional_chain,
  NULL, &backward_lstm_1_layer, AI_STATIC, 
  .axis = AI_SHAPE_CHANNEL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  forward_lstm_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &permute_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &forward_lstm_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 9, &forward_lstm_kernel, &forward_lstm_recurrent, &backward_lstm_peephole, &forward_lstm_bias, NULL, &backward_lstm_recurrent_params, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &forward_lstm_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  forward_lstm_layer, 2,
  LSTM_TYPE, 0x0, NULL,
  lstm, forward_lstm,
  &forward_lstm_chain,
  NULL, &bidirectional_layer, AI_STATIC, 
  .n_units = 16, 
  .activation_nl = nl_func_tanh_array_f32, 
  .go_backwards = false, 
  .reverse_seq = false, 
  .return_state = false, 
  .out_nl = nl_func_tanh_array_f32, 
  .recurrent_nl = nl_func_hard_sigmoid_array_f32, 
  .cell_clip = 3e+38, 
  .state = AI_HANDLE_PTR(NULL), 
  .init = AI_LAYER_FUNC(NULL), 
  .destroy = AI_LAYER_FUNC(NULL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  backward_lstm_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &permute_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &backward_lstm_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 9, &backward_lstm_kernel, &backward_lstm_recurrent, &backward_lstm_peephole, &backward_lstm_bias, NULL, &backward_lstm_recurrent_params, NULL, NULL, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &backward_lstm_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  backward_lstm_layer, 2,
  LSTM_TYPE, 0x0, NULL,
  lstm, forward_lstm,
  &backward_lstm_chain,
  NULL, &forward_lstm_layer, AI_STATIC, 
  .n_units = 16, 
  .activation_nl = nl_func_tanh_array_f32, 
  .go_backwards = true, 
  .reverse_seq = true, 
  .return_state = false, 
  .out_nl = nl_func_tanh_array_f32, 
  .recurrent_nl = nl_func_hard_sigmoid_array_f32, 
  .cell_clip = 3e+38, 
  .state = AI_HANDLE_PTR(NULL), 
  .init = AI_LAYER_FUNC(NULL), 
  .destroy = AI_LAYER_FUNC(NULL), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  permute_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &permute_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  permute_layer, 1,
  TRANSPOSE_TYPE, 0x0, NULL,
  transpose, forward_transpose,
  &permute_chain,
  NULL, &backward_lstm_layer, AI_STATIC, 
  .out_mapping = AI_SHAPE_INIT(6, AI_SHAPE_IN_CHANNEL, AI_SHAPE_HEIGHT, AI_SHAPE_WIDTH, AI_SHAPE_CHANNEL, AI_SHAPE_DEPTH, AI_SHAPE_EXTENSION), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1d_conv2d_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1d_conv2d_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1d_conv2d_weights, &conv1d_conv2d_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1d_conv2d_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_if32of32wf32,
  &conv1d_conv2d_chain,
  NULL, &permute_layer, AI_STATIC, 
  .groups = 1, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .in_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
  .out_ch_format = AI_LAYER_FORMAT_CHANNEL_LAST_VALID, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 869388, 1, 1),
    869388, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16416, 1, 1),
    16416, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BILSTM_MODEL_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BILSTM_MODEL_OUT_NUM, &dense_1_dense_output),
  &conv1d_conv2d_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 869388, 1, 1),
      869388, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 16416, 1, 1),
      16416, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BILSTM_MODEL_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_BILSTM_MODEL_OUT_NUM, &dense_1_dense_output),
  &conv1d_conv2d_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool bilstm_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_bilstm_model_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    input_0_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 32);
    input_0_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 32);
    
    conv1d_conv2d_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    conv1d_conv2d_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    
    permute_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 32);
    permute_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 32);
    
    backward_lstm_scratch0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 64);
    backward_lstm_scratch0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 64);
    
    backward_lstm_output0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 512);
    backward_lstm_output0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 512);
    
    forward_lstm_scratch0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 64);
    forward_lstm_scratch0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 64);
    
    forward_lstm_output0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 1024);
    forward_lstm_output0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 1024);
    
    bidirectional_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 1536);
    bidirectional_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 1536);
    
    backward_lstm_1_scratch0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 2560);
    backward_lstm_1_scratch0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 2560);
    
    backward_lstm_1_output0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 4352);
    backward_lstm_1_output0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 4352);
    
    forward_lstm_1_scratch0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 2560);
    forward_lstm_1_scratch0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 2560);
    
    forward_lstm_1_output0_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 6400);
    forward_lstm_1_output0_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 6400);
    
    bidirectional_1_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    bidirectional_1_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    
    dense_dense_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 4096);
    dense_dense_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 4096);
    
    re_lu_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    re_lu_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 0);
    
    dense_1_dense_output_array.data = AI_PTR(g_bilstm_model_activations_map[0] + 512);
    dense_1_dense_output_array.data_start = AI_PTR(g_bilstm_model_activations_map[0] + 512);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool bilstm_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_bilstm_model_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv1d_conv2d_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1d_conv2d_weights_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 0);
    conv1d_conv2d_weights_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 0);
    
    conv1d_conv2d_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1d_conv2d_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 131072);
    conv1d_conv2d_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 131072);
    
    backward_lstm_kernel_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_kernel_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 131104);
    backward_lstm_kernel_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 131104);
    
    backward_lstm_recurrent_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_recurrent_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 131360);
    backward_lstm_recurrent_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 131360);
    
    backward_lstm_peephole_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_peephole_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 135456);
    backward_lstm_peephole_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 135456);
    
    backward_lstm_bias_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 135648);
    backward_lstm_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 135648);
    
    backward_lstm_recurrent_params_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_recurrent_params_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 135904);
    backward_lstm_recurrent_params_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 135904);
    
    forward_lstm_kernel_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_kernel_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 135912);
    forward_lstm_kernel_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 135912);
    
    forward_lstm_recurrent_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_recurrent_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 136168);
    forward_lstm_recurrent_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 136168);
    
    forward_lstm_bias_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 140264);
    forward_lstm_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 140264);
    
    backward_lstm_1_kernel_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_1_kernel_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 140520);
    backward_lstm_1_kernel_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 140520);
    
    backward_lstm_1_recurrent_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_1_recurrent_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 173288);
    backward_lstm_1_recurrent_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 173288);
    
    backward_lstm_1_peephole_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_1_peephole_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 238824);
    backward_lstm_1_peephole_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 238824);
    
    backward_lstm_1_bias_array.format |= AI_FMT_FLAG_CONST;
    backward_lstm_1_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 239592);
    backward_lstm_1_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 239592);
    
    forward_lstm_1_kernel_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_1_kernel_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 240616);
    forward_lstm_1_kernel_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 240616);
    
    forward_lstm_1_recurrent_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_1_recurrent_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 273384);
    forward_lstm_1_recurrent_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 273384);
    
    forward_lstm_1_bias_array.format |= AI_FMT_FLAG_CONST;
    forward_lstm_1_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 338920);
    forward_lstm_1_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 338920);
    
    dense_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_weights_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 339944);
    dense_dense_weights_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 339944);
    
    dense_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_dense_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 864232);
    dense_dense_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 864232);
    
    dense_1_dense_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_1_dense_weights_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 864744);
    dense_1_dense_weights_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 864744);
    
    dense_1_dense_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_1_dense_bias_array.data = AI_PTR(g_bilstm_model_weights_map[0] + 869352);
    dense_1_dense_bias_array.data_start = AI_PTR(g_bilstm_model_weights_map[0] + 869352);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_bilstm_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_BILSTM_MODEL_MODEL_NAME,
      .model_signature   = AI_BILSTM_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 582293,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_bilstm_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_BILSTM_MODEL_MODEL_NAME,
      .model_signature   = AI_BILSTM_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 582293,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_bilstm_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_bilstm_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_bilstm_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_bilstm_model_create(network, AI_BILSTM_MODEL_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_bilstm_model_data_params_get(&params) != true) {
        err = ai_bilstm_model_get_error(*network);
        return err;
    }
#if defined(AI_BILSTM_MODEL_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_BILSTM_MODEL_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_bilstm_model_init(*network, &params) != true) {
        err = ai_bilstm_model_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_bilstm_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_bilstm_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_bilstm_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_bilstm_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= bilstm_model_configure_weights(net_ctx, params);
  ok &= bilstm_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_bilstm_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_bilstm_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_BILSTM_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

