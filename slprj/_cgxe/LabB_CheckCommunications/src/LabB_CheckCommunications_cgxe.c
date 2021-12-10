/* Include files */

#include "LabB_CheckCommunications_cgxe.h"
#include "m_79H60AoriwQj1LzelpYjTG.h"

unsigned int cgxe_LabB_CheckCommunications_method_dispatcher(SimStruct* S, int_T
  method, void* data)
{
  if (ssGetChecksum0(S) == 2097057843 &&
      ssGetChecksum1(S) == 3416703484 &&
      ssGetChecksum2(S) == 3217673062 &&
      ssGetChecksum3(S) == 3191664327) {
    method_dispatcher_79H60AoriwQj1LzelpYjTG(S, method, data);
    return 1;
  }

  return 0;
}
