/*
 * Copyright 2010-2017 JetBrains s.r.o.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "KAssert.h"
#include "TypeInfo.h"

extern "C" {

// Seeks for the specified id. In case of failure returns a valid pointer to some record, never returns nullptr.
// It is the caller's responsibility to check if the search has succeeded or not.
InterfaceTableRecord const* LookupInterfaceTableRecord(InterfaceTableRecord const* interfaceTable,
                                                       int interfaceTableSize, ClassId interfaceId) {
  if (interfaceTableSize <= 8) {
    // Linear search.
    int i;
    for (i = 0; i < interfaceTableSize - 1 && interfaceTable[i].id < interfaceId; ++i);
    return interfaceTable + i;
  }
  int l = 0, r = interfaceTableSize - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (interfaceTable[m].id < interfaceId)
      l = m + 1;
    else r = m;
  }
  return interfaceTable + l;
}

}
