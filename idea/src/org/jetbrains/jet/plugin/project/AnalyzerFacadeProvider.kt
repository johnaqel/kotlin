/*
 * Copyright 2010-2014 JetBrains s.r.o.
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

package org.jetbrains.jet.plugin.project

import org.jetbrains.jet.lang.psi.JetFile
import org.jetbrains.jet.analyzer.new.AnalyzerFacade
import org.jetbrains.jet.lang.resolve.java.new.JvmAnalyzerFacade
import org.jetbrains.jet.plugin.caches.resolve.JsAnalyzerFacade

public object AnalyzerFacadeProvider {
    public fun getAnalyzerFacade(targetPlatform: TargetPlatform): AnalyzerFacade<*, *> {
        return when (targetPlatform) {
            TargetPlatform.JVM -> JvmAnalyzerFacade()
            TargetPlatform.JS -> JsAnalyzerFacade()
            else -> throw IllegalArgumentException("Unsupported platfrom: $targetPlatform")
        }
    }
}
